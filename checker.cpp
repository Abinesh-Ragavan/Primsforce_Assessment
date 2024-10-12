#include <bits/stdc++.h>
using namespace std;

bool checker(int index, vector<int>& enemies, int current_power, int behind_power, int recharge, int skip, int initial_power) {
    
    // Base condition
    
    if (index == enemies.size()) return true;

    bool op1 = false, op2 = false, op3 = false;
    
  
     // Handling regenerated power of k3 and k7
     
    if (current_power >= behind_power) {
    	
        current_power -= behind_power;
        behind_power = 0; // Reset behind power
        
    } else {
        return false; // Attacked by k3 or k7
    }


    // Case 1: Skip the circle
    
    if (skip > 0) {
        op1 = checker(index + 1, enemies, current_power, behind_power, recharge, skip - 1, initial_power);
    }


    // Case 2: Fight with the enemy
    
    if (current_power >= enemies[index]) {
    	
        int new_behind_power = behind_power;
        
        if (index == 2 || index == 6) {
        	
            new_behind_power = enemies[index] / 2; // Set regenerated power of k3 and k7
        }
        
        op2 = checker(index + 1, enemies, current_power - enemies[index], new_behind_power, recharge, skip, initial_power);
    }


  // Case 3: Recharge
  
    if (recharge > 0 && current_power < initial_power) {
    	
        op3 = checker(index , enemies, initial_power, behind_power, recharge - 1, skip, initial_power); 
    }
    
    // Return true if any of the cases work
    return op1 || op2 || op3;
}





int main() {
    vector<int> enemies(11);
    
    for(int i=0;i<11;i++){
    	cout<<"Enter the power of enemy "<<i<<"\n";
    	cin>>enemies[i];
	}
    int initial_power,recharge,skip;
    cout<<"Enter Initial power of Abhimanyu\n";
    cin>>initial_power;
    
    cout<<"Enter number of times to recharge\n";
    cin>>recharge;
    
    cout<<"Enter number of times to skip\n";
    cin>>skip;
    
    bool result = checker(0, enemies, initial_power, 0, recharge,skip,initial_power);

    if (result) {
        cout << "Abhimanyu Survived!" << endl;
    } else {
        cout << "Abhimanyu was defeated!" << endl;
    }

   
    return 0;
}
