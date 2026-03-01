#include <iostream>
#include <string>
using namespace std;

#define MAX 50
#define MAX_ACTIVITY 100

struct FriendProfile {
    int id;
    string name;
    string email;
    string status;
};

FriendProfile users[MAX];
int userCount = 0;

int graph[MAX][MAX] = {0};

string activityStack[MAX_ACTIVITY];
int top = -1;

// ---------------- Stack Operations ----------------
void pushActivity(string activity) {
    if(top < MAX_ACTIVITY - 1) {
        activityStack[++top] = activity;
    }
}

void undoActivity() {
    if(top == -1) {
        cout << "No activity to undo.\n";
        return;
    }
    cout << "Undoing: " << activityStack[top--] << endl;
}

// ---------------- Profile Management ----------------
void addFriend() {
    if(userCount >= MAX) {
        cout << "User limit reached.\n";
        return;
    }

    cout << "Enter ID: ";
    cin >> users[userCount].id;
    cout << "Enter Name: ";
    cin >> users[userCount].name;
    cout << "Enter Email: ";
    cin >> users[userCount].email;
    cout << "Enter Status: ";
    cin >> users[userCount].status;

    pushActivity("Added Friend: " + users[userCount].name);
    userCount++;
    cout << "Friend Added Successfully.\n";
}

int findUserIndex(int id) {
    for(int i = 0; i < userCount; i++) {
        if(users[i].id == id)
            return i;
    }
    return -1;
}

void removeFriend() {
    int id;
    cout << "Enter ID to remove: ";
    cin >> id;

    int index = findUserIndex(id);
    if(index == -1) {
        cout << "User not found.\n";
        return;
    }

    pushActivity("Removed Friend: " + users[index].name);

    for(int i = index; i < userCount - 1; i++) {
        users[i] = users[i+1];
    }
    userCount--;

    cout << "Friend Removed.\n";
}

// ---------------- Friendship Graph ----------------
void addFriendship() {
    int id1, id2;
    cout << "Enter First User ID: ";
    cin >> id1;
    cout << "Enter Second User ID: ";
    cin >> id2;

    int i = findUserIndex(id1);
    int j = findUserIndex(id2);

    if(i == -1 || j == -1) {
        cout << "Invalid IDs.\n";
        return;
    }

    graph[i][j] = 1;
    graph[j][i] = 1;

    pushActivity("Friendship Added between " + users[i].name + " and " + users[j].name);
    cout << "Friendship Added.\n";
}

void viewFriends() {
    int id;
    cout << "Enter User ID: ";
    cin >> id;

    int index = findUserIndex(id);
    if(index == -1) {
        cout << "User not found.\n";
        return;
    }

    cout << "Friends of " << users[index].name << ":\n";
    for(int i = 0; i < userCount; i++) {
        if(graph[index][i] == 1) {
            cout << users[i].name << endl;
        }
    }
}

// ---------------- Searching ----------------
void searchFriend() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    int index = findUserIndex(id);
    if(index == -1) {
        cout << "User not found.\n";
    } else {
        cout << "Found: " << users[index].name << endl;
    }
}

// ---------------- Sorting ----------------
void sortFriends() {
    for(int i = 0; i < userCount - 1; i++) {
        for(int j = 0; j < userCount - i - 1; j++) {
            if(users[j].name > users[j+1].name) {
                swap(users[j], users[j+1]);
            }
        }
    }
    cout << "Friends sorted by name.\n";
}

// ---------------- Display All ----------------
void displayAll() {
    for(int i = 0; i < userCount; i++) {
        cout << users[i].id << " - "
             << users[i].name << " - "
             << users[i].email << " - "
             << users[i].status << endl;
    }
}

// ---------------- Main Menu ----------------
int main() {
    int choice;

    do {
        cout << "\n=== Mini Social Network Friend Tracker ===\n";
        cout << "1. Add Friend Profile\n";
        cout << "2. Remove Friend Profile\n";
        cout << "3. Add Friendship\n";
        cout << "4. View Friends\n";
        cout << "5. Search Friend\n";
        cout << "6. Sort Friends\n";
        cout << "7. Display All Profiles\n";
        cout << "8. Undo Last Activity\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addFriend(); break;
            case 2: removeFriend(); break;
            case 3: addFriendship(); break;
            case 4: viewFriends(); break;
            case 5: searchFriend(); break;
            case 6: sortFriends(); break;
            case 7: displayAll(); break;
            case 8: undoActivity(); break;
            case 9: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 9);

    return 0;
}