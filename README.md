# CesiumProject
Brady Risendal -- 5/9/21

This is a project created for my application to Cesium for their Unreal 3D Software Developer position.


This project was created in Unreal Engine 4.26, with no extra plugins used or installed.

When opening the project, it will launch into the default 'FirstPersonExampleMap', with the player spawn moved to a platform off to the side. Within the level there is a blueprint actor called 'BP_TreeGen', which has several public variables. 

These variables are:
Spawn - actor dropdown menu that allows you to select any actor to spawn other than the selected tree model.

Spawn Count - an int value that determines how many trees to spawn.

Initial Spawn Delay - spawning all the trees right at the start of the application caused a hang-up, so a small delay was added (measured in seconds).

Spawn Delay - the time between spawning trees. Added for optimization; instead of spawning large numbers all at once, a slight delay relieves a bit of the processing stress.


After hitting play there will be a pause of Initial Spawn Delay before the trees begin to spawn. Hovering the mouse courser over a tree and clicking will display the targeted tree's location, height, and canopy radius. 

Escape key will end the game.
