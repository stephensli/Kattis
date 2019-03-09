#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

/**
 * The point is going to be the x and y position on the board.
 * This will be within the limits of the grid sizes.
 */
struct point final
{
	/*
	 * The x and y position of the point on the board.
	 */
	int x, y;
};

/**
 * Our point compare value, this will be used when we perform finds with
 * the point struct, used for when we are filtering out ignored points
 * when parsing the zones.
 */
inline bool operator==(const point& point_one, const point& point_two)
{
	return point_one.x == point_two.x && point_one.y == point_two.y;
}

class zone_layout final
{
public:
	/**
	 * The current zone value that is being set within the zone, we will use this when
	 * referencing to make sure we know what value is being inserted next. We will also
	 * be decreasing this value when changes go wrong and we pop the change off the stack.
	 */
	int current_value = 1;
	/**
	 * \brief A list of all the valid zone points on the zone, these are the positions
	 * which we are allowed to place values within, as long as they do also not
	 * touch another value on the board in any direction (which is the same value).
	 */
	vector<point> zone_points;
	/**
	 * These are values that can be skipped because the value
	 * is already on the board, we don't want to be doing anything but incrementing.
	 */
	set<int> skipped_values;
	int number_positions;
	/**
	 * \brief Default constructor, the zone points will be added after the creation of
	 * the zone layout and does not need to be passed in.
	 */
	zone_layout() = default;
};

class grid_layout final
{
private:
	/**
	 * \brief These are all the zone layouts that are currently on the board.
	 * this will not have the ignored points, these points will be removed
	 * before any zone data is added here.
	 */
	vector<zone_layout> zone_layouts_;
	/**
	 * \brief A list of all the ignored points on the board, these are points we cannot
	 * touch because there is already a value on the board. limiting us to what
	 * we can do in that selected zone.
	 */
	vector<point> ignored_points_;
	/**
	 * \brief This is the list of int values that is the actual points on the grid. This
	 * is the vector that will be mutated and changed / printed.
	 */
	vector<vector<int>> grid_;
public:
	/**
* \brief The number of rows and columns of the given grid, we can use this to define
* our limits and assign our memory locations, we will then take 1 value of each
* of these as we will be referencing the points by - 1 as well as they are parsed.
*/
	int number_rows{}, number_columns{};
	/**
	 * \brief The constructor with the required rows and columns that will be used to define
	 * the size of our vectors that will be containing the zones.
	 */
	grid_layout(int rows, int columns);
	grid_layout() = default;
	/**
	 * \brief This will parse a single line of a grid, this is important as we will need
	 * to locate and find all the values that are replaced, these will have to be
	 * added to the ignored list / ont allowed to go into the zones when the zones
	 * are parsed.
	 * \param line_number The line number that was parsed, used for indexing.
	 * \param line The actual line that was parsed.
	 */
	void parse_line(int line_number, string line);
	/**
	 * \brief This will parse each of the given zones that come after the grid has been
	 * given, in this process it will filter out any replaced positions in that
	 * zone and then create a zone layout of the given points in that zone.
	 */
	void parse_zone(string zone);
	/**
	 * validates that when we try to insert the value into the given section of the grid
	 * that the inserting value does not line up with any other value that has its same
	 * number, so 1 can not be next to one in any other direction at all.
	 */
	bool validate_can_insert_value(const int value, const point zone_position);
	/**
	 * \brief Performs the solving process of the algorithm, this process starts by
	 * 1. Sorting by the sets that have the smallest amount of values left to process.
	 * 2. insert the first value
	 * 3. Push the value to the stack
	 * 4. Check the next value, if it values pop of the stack
	 * 5. set the value back
	 * 6. set that position as a disallowed position and attempt to re-insert into that set again
	 * 7. if it fails repeat pop
	 * 8 else start back at 1.
	 */
	void solve(int zone_position, int zone_point_position);
	/**
	 * \brief Prints the given formatted layout of what is expected as the output. Each
	 * line with a single space with each value in that section.
	 */
	void print();
};

bool sort_by_smallest_spaces_left(zone_layout& zone_one, zone_layout& zone_two)
{
	return zone_one.zone_points.size() < zone_two.zone_points.size();
}

grid_layout::grid_layout(const int rows, const int columns)
{
	this->number_rows = rows;
	this->number_columns = columns;

	// define our base vector size with the number of rows we are going to need.
	this->grid_ = vector<vector<int>>(this->number_rows);

	// make sure we go through and allocate all the required memory
	// for the given rows and columns we are going to be filling.
	for (int i = 0; i < this->number_rows; ++i)
		this->grid_.at(i) = vector<int>(this->number_columns);

	// deduct 1 of each section, as our arrays start at 1 and we will be deducting 1
	// from all of our parsed points on the board. This will help reduce confusion
	// later on.
	this->number_rows -= 1;
	this->number_columns -= 1;
}

void grid_layout::parse_line(const int line_number, const string line)
{
	// get a list of all the tokens split on the space of the string
	// this will be used to check if we are adding a value / adding this
	// validate to the ignored points.
	istringstream iss(line);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };

	for (int i = 0; i < int(tokens.size()); ++i)
	{
		if (tokens.at(i) != "-")
		{
			this->grid_.at(line_number).at(i) = stoi(tokens.at(i));
			this->ignored_points_.push_back(point{ i, line_number });
		}
	}
}

void grid_layout::parse_zone(string zone)
{
	// take out all the values that are not numbers, we can then just
	// work with the raw number values.
	zone.erase(remove_if(zone.begin(), zone.end(), &::ispunct), zone.end());

	// once again generate the tokens, which is splitting the list on the spaces
	// we can then use this to parse each newly created point.
	istringstream iss(zone);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };

	zone_layout zone_layout;

	const int number_items_in_zone = stoi(tokens.at(0));
	vector<point> zone_points;

	zone_layout.number_positions = number_items_in_zone;

	for (int i = 1; i < int(tokens.size()); ++i)
	{
		// for each point we are actually going to take away 49 (48 for the ascii starting
		// point and then 1 more because our vector array is actually starting at 0 not 1).
		point point{ int(tokens.at(i)[1]) - 49, int(tokens.at(i)[0]) - 49 };

		// validate that this point is not being ignored already, we don't want to add a
		// point if its being ignored (due to a fixed value already existing in it).
		auto position = std::find(this->ignored_points_.begin(), this->ignored_points_.end(), point);

		if (position != this->ignored_points_.end())
		{
			// need to make sure to track this value that is in there, we want to skip this value
			// when we are incrementing the value n.
			zone_layout.skipped_values.insert(this->grid_.at(point.y).at(point.x));
			continue;
		}

		zone_layout.zone_points.push_back(point);
	}

	// add our newly parsed zone section into the zones for the grid.
	this->zone_layouts_.push_back(zone_layout);

	// first step is to sort by the smallest number of spaces left, we don't want to ruin this by making
	// the grid space with only one space left not be able to sort a value because we broke the properties
	// of the grid, so we want to start with the smallest first.

	// 1. ordering by the smallest allows us to get the best result for the smallest spaces first. Slowing working up to
	// the largest spaces next. Each time we pop we mark that spot as disallowed (until a pop or insert again).
	sort(this->zone_layouts_.begin(), this->zone_layouts_.end(), sort_by_smallest_spaces_left);
}

bool grid_layout::validate_can_insert_value(const int value, const point zone_position)
{
	// if can go left check left
	if (zone_position.x > 0)
	{
		if (this->grid_.at(zone_position.y).at(zone_position.x - 1) == value)
			return false;
	}

	// if can go right check right
	if (zone_position.x < this->number_columns)
	{
		if (this->grid_.at(zone_position.y).at(zone_position.x + 1) == value)
			return false;
	}

	// if can go up check up
	if (zone_position.y > 0)
	{
		if (this->grid_.at(zone_position.y - 1).at(zone_position.x) == value)
			return false;
	}

	// if can go down check down
	if (zone_position.y < this->number_rows)
	{
		if (this->grid_.at(zone_position.y + 1).at(zone_position.x) == value)
			return false;
	}

	// if can go top left go top left
	if (zone_position.x > 0 && zone_position.y > 0)
	{
		if (this->grid_.at(zone_position.y - 1).at(zone_position.x - 1) == value)
			return false;
	}

	// if can go top right go top right
	if (zone_position.x < this->number_columns && zone_position.y > 0)
	{
		if (this->grid_.at(zone_position.y - 1).at(zone_position.x + 1) == value)
			return false;
	}

	// if can go bottom left go bottom left
	if (zone_position.y < this->number_rows && zone_position.x > 0)
	{
		if (this->grid_.at(zone_position.y + 1).at(zone_position.x - 1) == value)
			return false;
	}

	// if can go bottom right, go bottom right
	if (zone_position.x < this->number_columns && zone_position.y < this->number_rows)
	{
		if (this->grid_.at(zone_position.y + 1).at(zone_position.x + 1) == value)
			return false;
	}

	return true;
}

void grid_layout::solve(const int zone_position, const int zone_point_position)
{
	// if we have gone through all the zone positions, and correctly located and found a 
	// corresponding position for that value, then we can print out the gird and exit
	// otherwise continue with the zone.
	if (zone_position == int(this->zone_layouts_.size()))
	{
		this->print();
		exit(0);
	}

	// if we have completed all the zone positions in the given zone (meaning we have
	// said that we want to go one more zone position forward than we have), then we are 
	// just going to want to move onto the next zone. (returning because we don't want to
	// attempt to access a zone field that is out of bounds of the memory when this execution is complete).
	if (int(this->zone_layouts_.at(zone_position).zone_points.size()) == zone_point_position)
	{
		solve(zone_position + 1, 0);
		return;
	}

	// lets start processing through all our values that are required to be inserted into
	// our grid. Starting from 1 and ending at the final number of positions.
	for (int i = 1; i <= this->zone_layouts_.at(zone_position).number_positions; ++i)
	{
		// determine the zone we are working with (making sure to use the reference so
		// we can keep the ignored list of values up to date.
		zone_layout& working_zone = this->zone_layouts_.at(zone_position);

		// lets determine if we have already used this value, and continue onto the next
		// value otherwise. If for what ever reason we could not solve the following 
		// number, we will take a step back and add the previous value back into the pot.
		auto skipped_values = working_zone.skipped_values.find(i);
		if (skipped_values != working_zone.skipped_values.end()) continue;

		// determine what point we are working with.
		const point & zone_point = working_zone.zone_points.at(zone_point_position);

		// lets set the value and insert it into our ignored list of numbers.
		// if it fails the validation checks, then we are just going to remove it anyway.
		this->grid_.at(zone_point.y).at(zone_point.x) = i;
		working_zone.skipped_values.insert(i);

		// if its all valid, lets continue again onto the next section of the given zone.
		if (this->validate_can_insert_value(i, zone_point))
			solve(zone_position, zone_point_position + 1);

		// if it could not solve the given zone or position then lets revert back a step, putting the value
		// back into the usable values once again. This would be hit if we failed to validate the complete
		// zone or a given value in the zone.
		this->grid_.at(zone_point.y).at(zone_point.x) = 0;
		working_zone.skipped_values.erase(i);
	}
}

void grid_layout::print()
{
	// iterate over all the rows and columns within the given grid and then
	// print out all the values for that given section of the grid. Making
	// sure to add in the spaces between each of the given values as per
	// the requirements.
	for (int i = 0; i < this->number_rows + 1; ++i)
	{
		for (int j = 0; j < this->number_columns + 1; ++j)
			std::cout << this->grid_.at(i).at(j) << " ";

		std::cout << endl;
	}
}

int main(int argc, char* argv[])
{
	int number_of_rows, number_of_columns;
	std::cin >> number_of_rows >> number_of_columns;

	// create our grid that we will use for parsing in the data.
	grid_layout grid = grid_layout(number_of_rows, number_of_columns);

	// after getting the first rows and columns, we have to call get line
	// to remove the new line that was left behind, otherwise than our
	// next input will be a new line.
	string line;
	getline(cin, line);

	for (int i = 0; i < number_of_rows; ++i)
	{
		// get our proper full line, this is what will be
		// passed and parsed by the grid line parsing.
		getline(cin, line);
		grid.parse_line(i, line);
	}

	// next stage is parsing in the number of  zones we are going to be working with.
	int number_zones;
	std::cin >> number_zones;

	//	removes the newline from getting a single int.
	getline(cin, line);

	// once again go through and parse in all the zones
	// zones that are pointing to already used positions will
	// be ignored.
	for (int i = 0; i < number_zones; ++i)
	{
		getline(cin, line);
		grid.parse_zone(line);
	}

	// solve the grid problem
	grid.solve(0, 0);
}