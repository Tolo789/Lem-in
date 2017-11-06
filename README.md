# Lem-in
42 project: graph teory / pathfinding

### Objective
Given a graph, find the fastest way to bring a given number of ants from a start point to an end point. (I use an implementation of the Dijkstra's algorithm)

### Project's constraints
The graph is to be given on the standard entry and must have the folowing structure:
- number of ants;
- rooms;
- connections.

The number of ants can be between 0 and 2147483647, if it is 0 no move will be displayed (see after).

Rooms must be given with the format "name x_coord y_coord". Only one room can be given per line and rooms with the same name or the same coordinates are not accepted.
In order to mark the starting and ending rooms the lines "##start" and/or "##end" must appear right above the room line.

Connections directly follow the rooms and must have the following format: "name1-name2", where "name1" and "name2" are the names of two different rooms. (Even in this case only one connection can be given per line)

It is possible to put as many commentaries as you like both in the rooms and connections sections.
To do this just start the line with the "#" character. (Please note that "##start" and "##end" are not seen as commentaries and will trigger an error if written in the connections section)

The map will be aquired one line at the time and if any error is detected (or if the file is ended) the parsing stops.
If with the retrieved data is impossible to find at least one path, "Error" will be displayed.

Otherwise the moves to bring all ants from the start to the end will be printed with the following line format: "L1-x L2-y .. L3-z". The "L1", "L2", etc stands for wich ants is being moved, while the "-x" part tells in which room the ants is being moved.
Each line stands for a "round", which has the following rules:
- the same ant can use only one connection per round;
- the same connection can be used only by one ant per turn;
- an ant can not be moved to a room if there is already another ant in the same room (except for the end room).

### Options
It is possible to give some flags to the program in order to change the behaviour of the program:
- -m: enables multi-pathfinding;
- -d: uses coordinates between rooms to workout the actual lenght of each connection;
- -p: displays all found paths with their infos;
- -t: shows total number of rounds and covered distance;
- -c: colors the movement when end room is reached by an ant;
- -d: displays help menu and closes program.

### Notes
- if the -h flag is given any other parameter given (acceptable or not) will not be considered and the help menu will be displayed without even considering the given map;
- all other flags are compatible with each other;
- if an invalid parameter is given "Error" will be displayed and the program ends.
