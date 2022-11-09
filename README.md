# Volleyball Rotation Generator
In volleyball, especially organized volleyball, players are put into positions. Depending on player preferences, different rotations can be made to utilize everyone's strengths. This tool will display the available legal rotatios based on teammembers' preferences and volleyball's team limits and constraints.

These position players can play are:
1. Setter
2. Libero
3. Middle
4. Outside
5. Opposite

Each position has a unique set of tasks that enable the team to be efficient in both offensive and defensive plays.


## Problem Statement
In casual/casual-competive leagues, players have more than one position they can play. This means at the time of team creation, the rotation is fluid as opposed to high competitive leagues in which players have focused on excelling in one particular role, and everyone falls into place.

Because players have more than one preference, many rotations exist. 

Ideal rotations have limits on player roles as well, which makes making some rotation more difficult than others. For example, a team with two libero players will be at a disadvantage as one of those players may have to play the role of a middle, where much taller players go.

The tool aims to aid in showing all the legitimate rotations available based on player preferences.

## Expected Outcome
The tool will generate and display all potential rotations, factoring in volleyball rotation rules and guidelines.

When there is an overflow of players with particular preference (for example, multiple players want to play Outside and do not have second preferences) the remaining players will be randomly selected to fill in any missing gaps.

## Outcome 
The tool currently goes through all the permutations of player positions, and cycles through a user inputted team style (think 5-1, 6-2), and checks if each permutation of the player positions will fit for the team style.

If the current selection of players fits the team, that team is added to a vector of Teams which can then later be printed.

## Future Goals
[] Expand on the Player class to add weighting to preferences, such that two Players with the same preferences will now have weights to their preferences, nudging them to their most preferred role.

[] Add multiple styles to display a team such as a displaying in a simple list or showing the rotation as if it was on the court.
