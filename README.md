# Restaurant-waitlist-system


CS211
–
Programming Practicum
Summer 2019
Command
Description
q
Quit the program.
?
List the commands used by this program and a
brief description
of how to use each one.
a <size> <name>
Add the group to the wait list using the given group size and name
specifying the group is waiting in the restaurant. The group’s
information is added to the end of the list. If the name already
exists in the wait list, give an error message and do not add the
information.
c <size> <name>
Add the group to the wait list using the given group size and name
specifying the group as a call ahead group. The group’s
information is added to the end of
the list. If the name already
exists in the wait list, give an error message and do not add the
information.
w <name>
Mark the call ahead group using the given name as waiting in the
restaurant. If the name does not exist is the wait list or is not a
ca
ll ahead group, give an error message.
r <table
-
size>
Retrieve and remove the first group on the wait list that is waiting
in the restaurant and is less than or equal to the table size. Note
that “first” is the group that has been in the wait list the lo
ngest.
l <name>
List total number of groups that are in the wait list in front of the
group specified by the given name. Also list the size of each group
that are in the wait list ahead of the group specified by the given
name. If the name does not
exist, give an error message.
d
Display the total number of groups in the wait list. Also display
the names, group size and in
-
restaurant status of all groups in the
wait list in order from first to last