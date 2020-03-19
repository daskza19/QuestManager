## Welcome!

Hi! I'm Josep Sànchez Arbona, student of the Bachelor's Degree in Videogames by UPC at [CITM](https://https://www.citm.upc.edu). This web is created for the second year's subject Project 2 that I have to do a Personal Reserch that consists in [Quest Manager](https://github.com/daskza19/QuestManager).
![Josep Sànchez Arbona](https://raw.githubusercontent.com/daskza19/QuestManager/master/Web%20Files/Images/Images/Foto%20Perfil.png)

## Introduction

First of all, what is Quest Managers? 


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
