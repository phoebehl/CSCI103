	//Save counters to some kind of stats arrays (for first 4 games)
		if (count < 4)
		{
			cumTD[0][count*2] = homeTD;
			cumTD[0][(count*2)+1] = awayTD;
			cumFG[0][count*2] = homeFG;
			cumFG[0][(count*2)+1] = awayFG;
		}

	//Save counters to stats arrays
		if (count > 3 && count < 5)
		{
			for (int i = 0; i < 8; i++)
			{
				if (inPlay[i] == false && i < 4)
				{
					cumTD[1][i] = homeTD;
					cumFG[1][i] = homeFG;
				}

				if (inPlay[i] == false && i > 3)
				{
					cumTD[1][i] = awayTD;
					cumFG[1][i] = awayFG;
				}
			}
		}

		if (count == 6)
		{
			for (int i = 0; i < 8; i++)
			{
				if (inPlay[i] == false && i < 4)
				{
					cumTD[2][i] = homeTD;
					cumFG[2][i] = homeTD;
				}

				if (inPlay[i] == false && i > 4)
				{
					cumTD[2][i] = awayTD;
					cumFG[2][i] = awayFG;
				}
			}
		}

	for (int i = 0; i < 8; i++)
	{
		cout << setw(3) << cumTD[0][i];

	}
	cout << endl;

	//EXTRA TESTING STUFF

	cumTD[0][0] = homeTD;
	cumTD[0][1] = awayTD;
	cumFG[0][0] = homeFG;
	cumFG[0][1] = awayFG;

	for (int i = 0; i < 8; i++)
	{
		cout << cumTD[0][i];
	}
	cout << endl << "fieldgoals";
	for (int i = 0; i < 8; i++)
	{
		cout << cumFG[0][i];
	}