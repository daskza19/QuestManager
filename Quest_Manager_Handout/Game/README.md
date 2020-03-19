## Welcome!

Hi! I'm Josep Sànchez Arbona, student of the Bachelor's Degree in Videogames by UPC at [CITM](https://https://www.citm.upc.edu). This web is created for the second year's subject Project 2 that I have to do a Personal Reserch that consists in [Quest Manager](https://github.com/daskza19/QuestManager).
![Josep Sànchez Arbona](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/Images/Foto%20Perfil.png)

## Introduction

Before talking about the Quest Manager we have to know clearly that it is a Quest. A quest (or mission), within the scope of Video Games, is a task that players can complete to earn a reward. It is normally used in role-playing games. The quests are used to give the player a certain loot, pass the level, etc.

There are different types of Quest which are:
* Kill Quests: The ones that tell the player to defeat an enemy.
* Combo Quests: Those that require the player to make a certain combo to overcome it.
* Delivery Quests: These are the ones that make the player go to a certain location to deliver / receive an item.
* Gather Quests: They are the ones that make the player collect a certain number of items.
* Escort Quests: They are the ones that protect an NPC / object by a dangerous map.
* Syntax Quests: They are the ones that make the player choose the correct syntax, it is used in text games.
* Hybrids: The ones that mix the different types of Quests.

The quests may have other quests within themselves and all of them are responsible for making the story progress. Side missions can be called "sidequests".

So then, on this page we are going to see how to make a Quest Manager to organize all the quests we have in the game. The system must be able to organize events using an XML file that can be activated or deactivated when finished.

## Quests and Events Structure?

To create a quest manager we first have to design the quests themselves (their types of states, rewards or sidequests that will be incorporated). All this we have to think about putting it in an .xml file. When I thought about that, an idea occurred to me, to make two types of structures, quests and events.

Before talking about its structure in the code we have to be clear about what a quest and an event are. It has been thought that with an example one would understand more.

The clear definition of what an event is is everything that happens when an action that has been prepared previously is carried out. They are usually short actions, such as when in Super Mario the character touches a coin and it disappears and is added to the score. An event is a scheduled short action. Following the previous example and applying it to a quest, this would differ if, in addition to taking a coin (scheduled event), we tell the player that he has to take x coins (thus creating a mission made up of different events).

So then, in this quest we need an event to activate it. This could be talking to an NPC or taking the first coin. So then we would have to create the event "TALK_WITH_NPC" or "TAKE_FIRST_COIN". The following is an example of creating an event:

There are two types of events, the ones that start the quest and the intermediate ones to complete it. When all the events in a quest are completed, it will be ended and give the player a reward, also going through the list of "endedQuests" within the Quest Manager.

So then, these would be the main structures of a quest and an event:

* Quests: The quests will consist of your identifier and reward. They will also be formed by the event that activates the Quest itself and (if it has), its sidequests. Later it will be seen that these quests are put on three different lists within the Quest Manager: the “listedQuests”, “activedQuests” and the “endedQuests”.


* Events: As previously mentioned, we will also create a new structure called “Events”, this firstly is formed by a type that distinguishes it. In my code I have implemented a "TOUCH_EVENT", which makes you have to press to pass the event. As stated, a quest (the structure shown above) has events within it. When all the events in a quest have been completed, the quests will be ended and therefore they will be placed on their respective list within the Quest Manager.

## The Quest Manager

The basic structure of the Quest Manager is shown below:

As you can see in the image, the Quest Manager is made up of the main functions: its constructor and destroyer and the Awake and Start functions. Then it also contains three lists where the prepared, active and finished quests will be saved and the xml file itself where all the data of the quests and events will be saved. The other functions are used to organize and read the xml data.

## Quests in our XML file

Having already explained the theory, before starting with the TODOs to apply it to practice, it was thought that it would be useful to teach how the data will be taken from the xml and its basic structure. Below is an image of it:

As explained above, quests have two ints that set it apart and explain what rewards they will give the player. So then, quests have their DNI (a normal int) and their rewards. The latter, because this exercise does not seek great depth but to understand the operation of the Quest Manager,
are the pixels that resize the character.

Within each quest you can see the activation event and its sub-events. Events have a similar structure, their xml type is related to the enum of the code. In this example, type 1 is related to the “TOUCH_EVENT”

## Practical Part

![TODO 0](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2000.png)
Look at the structure mentioned above presented by the Quests, Events and the Quest Manager.

![TODO 1](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2001.png)
Look at the structure mentioned above that presents the questData.xml.

![TODO 2](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2002.png)
We will need to read in the QuestManager Start the own xml file that will contain all the necessary data for quests and events. As in config.xml, a specific myApp function has been created for read this file.
The function is called LoadQuestsXML.

![TODO 3](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2003.png)
Respecting the structure that has been seen in the xml in TODO 1, all the data will have to be read and equaled with those of a new Quest that we will create.
To do this, we will create a loop that goes through all the quests in the questData file. Inside the loop, a new quest will be created (with the class that was created previously) and its DNI and Reward will be taken from the xml file.

![TODO 4](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2004.png)
See how the createEvent () function works.

![TODO 5](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2005.png)
Now the function seen in the last TODO is applied. As you can see, it is matched with the activationEvent of the quest. Now you have to do the same but with all the subEvent presented by the quests, so you will have to create a for going through all the subEvent and entering them in the list of subMissions within the quest itself.
To introduce them we can use the push_back() function and pass it as parameter the new event (created with the createEvent function).  

![TODO 6](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2006.png)
Pass the quest that has already made the activation event from the list of preparedQuests to activatedQuests (we can put the quest on the list using the push_back() function and we remove it from the previous list with the erase() function.

![TODO 7](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2007.png)
Add to the heights and ampoules of the ValidArea and PlayerRect rectangles the reward of the SubMission. Then remove the already completed subMission from the list (remember that it can be done with the erase () function).

![TODO 8](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2008.png)
Moving the already completed activated quests into the list of endedQuests and removing it from the list of activatedQuests (very similar to TODO 6).

![TODO 9](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2009.png)
Create a new quest (the third one) from the xml. For that we will put these data:

![TODO 9 DATA](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/TODOs/TODO%2010.png)
