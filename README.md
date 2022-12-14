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

## State Machine Design

This project uses a MenuDriver which is built on a state machine design to handle the available actions and paths that the user is allowed to use in the app. By using states, each higher level state can be written cleanly and with better focus.

```mermaid
stateDiagram-v2
  [*] --> Intro
  Intro --> Overview : o, overview
  Intro --> ShowTeams : s, show
  Intro --> Quit
  Intro --> ManageTeam : e, edit
  ShowTeams --> Quit
  ShowTeams --> Intro
  Overview --> Quit
  Overview --> Intro : i, intro
  ManageTeam --> Quit
  ManageTeam --> NewTeam : n, newteam
  ManageTeam --> EditTeam : e, edit
  ManageTeam --> ChangeRotation : c, change rotation
  NewTeam --> EditTeam
  EditTeam --> BuildRotations : s, save team
  ChangeRotation --> BuildRotations
  BuildRotations --> ManageTeam

  Quit --> [*]
```

## Results

The tool currently goes through all the permutations of player positions, and cycles through a user inputted team style (think 5-1, 6-2), and checks if each permutation of the player positions will fit for the team style.

If the current selection of players fits the team, that team is added to a vector of Teams which can then later be printed.

A Menu Driver has been written that allows the user to get an overview of the team, and cycle through all of the possible rotations.

## Future Goals

[x] Expand on the Player class to add weighting to preferences, such that two Players with the same preferences will now have weights to their preferences, nudging them to their most preferred role.

-- This goal is not necessary anymore unless a "strongest available team" option needs to be created

[] Add multiple styles to display a team such as a displaying in a simple list or showing the rotation as if it was on the court.

[] Add team editing options within the menu driver, such as addition or removal of players

-- This requires moving the business logic into the MenuDriver or the VolleyballTeam files as right now the teams are generated within main.cpp. To generate rotations with any team modifications, that ability needs to be pushed into a reusable function.
