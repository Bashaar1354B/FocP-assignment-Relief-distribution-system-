//Read the "README" file before running program
#include <iostream>
using namespace std;

int TrucksCheck(int RemainTrucks, int Trucks, int Score)	//Reuseable block of code for sending trucks so that there is no need to write it multiple times in the main code
{
	if (RemainTrucks >= Trucks * Score / 100)
	{
		cout << Trucks * Score / 100 << " Trucks were sent." << endl;
		RemainTrucks -= Trucks * Score / 100;
	}
	else if(RemainTrucks > 0)
	{
		cout << "Insuffiecient number of remaining trucks. The number needed was " << Trucks * Score / 100 << ", but we only have " << RemainTrucks << ", so sending all remaining trucks" << endl;
		RemainTrucks = 0;
	}
	else
	{
		cout << "No trucks can be sent" << endl;
	}
	return RemainTrucks;
}

int SupplyCheck(int RemainSupply, int Supply, int Score)	//Reuseable block of code for sending Supply so that there is no need to write it multiple times in the main code
{
	if (RemainSupply >= Supply* Score / 100)
	{
		cout << Supply * Score / 100 << " Supplies were sent." << endl;
		RemainSupply -= Supply * Score / 100;
	}
	else if (RemainSupply > 0)
	{
		cout << "Insuffiecient number of remaining Supply. The number needed was " << Supply * Score / 100 << ", but we only have " << RemainSupply << ", so sending all remaining Supply" << endl;
		RemainSupply = 0;
	}
	else
	{
		cout << "No Supply can be sent" << endl;
	}
	return RemainSupply;
}

int AmbulanceCheck(int RemainAmbulance, int Ambulance, int Score)	//Reuseable block of code for sending ambulances so that there is no need to write it multiple times in the main code
{
	if (RemainAmbulance >= Ambulance * Score / 100)
	{
		cout << Ambulance * Score / 100 << " Ambulance(s) were sent." << endl;
		RemainAmbulance -= Ambulance * Score / 100;
	}
	else if (RemainAmbulance > 0)
	{
		cout << "Insuffiecient number of remaining Ambulances. The number needed was " << Ambulance * Score / 100 << ", but we only have " << RemainAmbulance << ", so sending all remaining Ambulances." << endl;
		RemainAmbulance = 0;
	}
	else
	{
		cout << "No Ambulances can be sent" << endl;;
	}
	return RemainAmbulance;
}

int main()
{
	string AccessRoute, Warnings, ReliefNeeded, CommunictaionStatus;
	int RemainTrucks = 10, Trucks = 10, RemainSupply = 120, Supply = 120, Helicopters = 2, TempScore, RemainAmbulances = 5, Ambulances = 5, Topology, AreaType, PreviousAid, DamageLevel, PeopleInjured, score;

	cout << "Is there any relief needed(Yes/No): ";
	cin >> ReliefNeeded;

	while (ReliefNeeded == "Yes" || ReliefNeeded == "yes" || ReliefNeeded == "YES")
	{
		score = 0;
		cout << "Were there any previous warnings or signs of the Tornado(Yes/No): ";
		cin >> Warnings;
		cout << "Enter the damage/destruction level caused by the Tornado from 0-5: ";
		cin >> DamageLevel;
		cout << "Enter the Number of people injured during the event: ";
		cin >> PeopleInjured;
		cout << "Enter whether or not there has been previous aid(press 1 for yes or 2 for No): ";
		cin >> PreviousAid;
		cout << "Enter what the communication status is in the area(Online/Offline): ";
		cin >> CommunictaionStatus;
		cout << "Is the access route open to the area(Yes/No): ";
		cin >> AccessRoute;
		cout << "What is the type of area(press 1 for Rural or 2 for Urban): ";
		cin >> AreaType;
		cout << "What is the topology of the affected area(press 1 for Mountaineous, 2 for Plains or 3 for RiverSide): ";
		cin >> Topology;
		
		//Calculating the Need score

		//Calculating score addition by Damage Level
		score += DamageLevel * 5;
		//Calculating score addition using the input of previous warning of disaster
		if (Warnings == "No" || Warnings == "no" || Warnings == "NO")
			score += 5;
		//Calculating addition of score based on ranges of people injured
		if (PeopleInjured <= 50 && PeopleInjured > 10)
			score += 5;
		else if (PeopleInjured <= 100 && PeopleInjured > 50)
			score += 10;
		else if (PeopleInjured <= 150 && PeopleInjured > 100)
			score += 15;
		else if (PeopleInjured > 150)
			score += 20;
		//Using a ternary operator to change score using the input from prvious aid given
		score += (PreviousAid == 1) ? -5 : 10;
		//Communication status score editor
		if (CommunictaionStatus == "Offline" || CommunictaionStatus == "offline" || CommunictaionStatus == "OFFLINE")
			score += 10;
		//changing score based on the topology of the area
		switch (Topology)
		{
		case 1:
			score += 0;
			break;
		case 2:
			score += 10;
			break;
		case 3:
			score += 5;
			break;
		}
		//Changing score based on is the access route is open or not
		if (AccessRoute == "Yes" || AccessRoute == "yes" || AccessRoute == "YES")
			score += 5;
		//Changing score based on the type of area the disaster took place in
		switch (AreaType)
		{
		case 1:
			score += 5;
			break;
		case 2:
			score += 10;
			break;
		}
		
		cout << "The total calculate score is " << score << "." << endl;
		//Sending Resources
		if (score > 0)
		{
			RemainSupply = SupplyCheck(RemainSupply, Supply, score);
			if (Topology == 1 || AccessRoute == "No" || AccessRoute == "NO" || AccessRoute == "no")
			{
				TempScore = score - 20;
				if (TempScore < 0)
					TempScore = 0;
				RemainTrucks = TrucksCheck(RemainTrucks, Trucks, TempScore);
				RemainAmbulances = AmbulanceCheck(RemainAmbulances, Ambulances, TempScore);
				if (Helicopters != 0)
				{
					cout << "There was 1 helicopter sent." << endl;
					Helicopters -= 1;
				}
				else
				{
					cout << "There is no remaining helicopter to be sent." << endl;
				}
			}
			else
			{

				RemainTrucks = TrucksCheck(RemainTrucks, Trucks, score);
				RemainAmbulances = AmbulanceCheck(RemainAmbulances, Ambulances, score);
			}
		}
		else
		{
			cout << "No resources were sent because the score calculated was 0." << endl;
		}
		cout << endl;
		cout << "There are " << RemainAmbulances << " Ambulances left, " << RemainTrucks << " Trucks left, " << RemainSupply << " Supply remains and " << Helicopters << " Helicopters remain." << endl;
		
		//Checking whether there is more relief needed
		cout << "********" << endl;
		if (RemainSupply != 0 || RemainTrucks != 0)
		{
			cout << "Is there any more places where relief is needed(Yes/No): ";
			cin >> ReliefNeeded;

		}
		else
		{
			cout << "There can be no more relief provided due to insufficient resources." << endl;
			break;
		}
	}
	return 0;
}
