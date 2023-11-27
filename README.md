# Team-Task-Buddy
Problem Statement:

Today, it’s so confusing for everyone about who’s doing what in a group project. So, we need a simple system that helps team work together smoothly. Team Task Buddy is a personal project developed to address the challenges associated with team collaboration and task management. This project aims to provide an efficient and user-friendly platform for teams to organize, assign, and track tasks seamlessly.

Objectives:

~  develop a system that allows user to add task with ease, ensuring a simple process for assigning task to team members.
~ a dashboard where you can see all task in one go. No more searching here and there. Everything you need, right in front of you.
~ our program should be easy to use that even someone who’s not great with technology can use it.
~ a system that is adaptable to different projects, allowing to customize it based on specific requirements of their project.
~ to implement feature which facilitate smooth communication and allow team members to discuss task and deadlines.


Algorithm Used:

Structure:
Define a structure “task” to represent task that includes task description, assignee, a pointer to the next task, and a dependency pointer.

Function:

~ Main function: initialize a pointer to task list (struct Task * taskList) and variable for user input like description and assignee.
 A while loop allowing users to:
-add a new task including task description and assignee name.
-view all tasks in list.
-Exit the program.

~ addTask Function:
- allocate memory for new task using “malloc” and for that we also need <stdlib.h>.
- copy description and assignee to new task.
- add new task to beginning of linked list.

~ printTasks Function:
- iterate through linked list and print details of each task.

~ freeTasks Function:
- iterate through linked list and free allocated memory for each task.

Finding task by Dependency description:
When adding a task, search the linked list for a task with a description matching the provided dependency description. If found, set the dependency pointer of the new task to point to the found task.

Memory Management:
Handle memory allocation failures and ensure proper management.

User Interface:
Present a user friendly menu and interact with the user based on their choices.

Loop Handling:
Continuously prompt the user until they opt to exit by utilizing a loop.
Impact:
 Making the Team Task Buddy aimed at streamlining team communication, improving project efficiency, and fostering accountability. Its practical applications showcase the versatility of computer science, with potential benefits for industries reliant on effective collaboration, addressing real-world challenges in team dynamics.
It can be improved by adding security measures and user authentication and authorization or enhancing searching and filtering options but I have used only what I know right now.

Conclusion:
Team Task Buddy presents an innovative solution to enhance teamwork and project management efficiency. By introducing assignees and task dependencies, the system encourages accountability and seamless collaboration among team members. The impact of this project extends beyond individual productivity, contributing positively to broader social well-being within a collaborative work environment.
This project not only showcases technical proficiency in linked list manipulation and user interface design but also emphasizes the importance of effective communication and responsibility distribution in team-based projects. 





Name: Rahul Choudhary






