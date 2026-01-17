#include <iostream>
using namespace std;

int main() {
    int N = 0;
    int choice;
    float temp[100]; 

    do {
        cout << "\n******** Daily Temperature Data Logger ********\n";
        cout << "1. Input Temperature Readings\n";
        cout << "2. Display Readings\n";
        cout << "3. Update Reading\n";
        cout << "4. Linear Search\n";
        cout << "5. Find Maximum and Minimum\n";
        cout << "6. Calculate Average\n";
        cout << "7. Reverse Readings\n";
        cout << "8. Exit\n";
        cout << "*********************************************\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        // Step 1: Input Temperature Readings
        case 1:
            cout << "Enter number of days: ";
            cin >> N;

            for (int i = 0; i < N; i++) {
                cout << "Day " << i + 1 << ": ";
                cin >> temp[i];
            }
            cout << "Temperature readings stored successfully.\n";
            break;

        // Step 2: Display All Readings
        case 2:
            cout << "\nTemperature Readings:\n";
            for (int i = 0; i < N; i++) {
                cout << "Day " << i + 1 << ": " << temp[i] << "°C\n";
            }
            break;

        // Step 3: Update Temperature Reading
        case 3: {
            int day;
            float newTemp;
            cout << "Enter day to update (1-" << N << "): ";
            cin >> day;
            cout << "Enter new temperature: ";
            cin >> newTemp;

            temp[day - 1] = newTemp;
            cout << "Updated temperature for Day " << day << ".\n";
            break;
        }

        // Step 4: Linear Search
        case 4: {
            float searchTemp;
            bool found = false;
            cout << "Enter temperature to search (Linear Search): ";
            cin >> searchTemp;

            for (int i = 0; i < N; i++) {
                if (temp[i] == searchTemp) {
                    cout << "Temperature " << searchTemp << "°C found on Day " << i + 1 << ".\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Temperature not found.\n";
            }
            break;
        }

        // Step 5: Find Maximum and Minimum
        case 5: {
            float max = temp[0];
            float min = temp[0];

            for (int i = 1; i < N; i++) {
                if (temp[i] > max)
                    max = temp[i];
                if (temp[i] < min)
                    min = temp[i];
            }
            cout << "Maximum Temperature: " << max << "°C\n";
            cout << "Minimum Temperature: " << min << "°C\n";
            break;
        }

        // Step 6: Calculate Average Temperature
        case 6: {
            float sum = 0;
            for (int i = 0; i < N; i++) {
                sum += temp[i];
            }
            float average = sum / N;
            cout << "Average Temperature: " << average << "°C\n";
            break;
        }

        // Step 7: Reverse Temperature Readings
        case 7:
            for (int i = 0; i < N / 2; i++) {
                float swap = temp[i];
                temp[i] = temp[N - 1 - i];
                temp[N - 1 - i] = swap;
            }
            cout << "Readings reversed successfully.\n";
            break;

        // Step 8: Exit Program
        case 8:
            cout << "Exiting program. Thank you!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
