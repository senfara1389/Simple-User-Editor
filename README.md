# Simple-User-Editor

This is a working version that currently has no custom styling, no adding or deleting users and no search function.
It does have JSON reading and parsing, creating models from data parsed from JSON and displaying them in the GUI, as well as interactions between some GUI Widgets such as
displaying detailed data on the user selected in the brief user list, as well as displaying their image if they have one.
It also includes a simple JSON file that contains some of the sample data that's supposed to be displayed in the application.

Update 1.0

I managed to add the user deletion option before the option to add the users. Pretty genius, I know.
Now you can select the user on the left list and press delete and it will be deleted from the list, the detailed list and the JSON file.

Update 2.0

I finally added the adding new users option. Too bad it still doesn't have any validation so you can basically type in your
credit card number for your last name and it will be accepted (don't do that).
So I still have to do the validation, to eat some of the spaghetti that can be found inside the code so it looks at least
somewhat as if an actual programmer did it. 
In the end, it's all about style, so the final version will look better than the Windows XP background and it will be your
new favorite art piece after I finish with the stylesheets. I'm off to my hibernation now since I spent almost 12 consecutive
hours making this.

Update 3.0

Finally added user validation on entry as well as done some major code refactoring so now every interaction and connection that needs to be created is in a separate file from the classes.

Only thing that's left is to refactor the code pretaining to the widget creation (lots of duplicate functions)
and add some style.

Update 4.0

The odyssey has finally come to an end. The app looks like a classic 80s command line so you feel like a real hacker while adding
your childhood friend Bumbo to the app and pretending to delete Elon Musk from your database of employees. Search function still 
doesn't work but for now, I consider this finished because it serves its purpose. It was a fun ride but I'd do it pretty differently now that I'm wise and experienced.
