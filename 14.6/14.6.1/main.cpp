int main(){
	//counting from the head of the table
	// [12] for 12 places, 
	// [8] for fork, spoon, knife, dessert spoon for VIP only, +4 
	// first plate, secod plate, dessert plate VIP only, - +3
	// chairs + 1. Total: 8
	//
	//
	// places:
	//
	// -------------------------------------
	// |0:vip|1:nor|2:nor|3:nor|4:nor|5:nor|
	// -------------------------------------
	// |              TABLE                |
	// -------------------------------------
	// |6:vip|7:nor|8:nor|9:nor|10:no|11:no|
	// -------------------------------------
	//
	// second array = {
	// 		    0:fork, 
	// 		    1:spoon, 
	// 		    2:knife,
	// 		    3:desert spoon,
	// 		    4:first plate,
	// 		    5:second plate,
	// 		    6:desser plate,
	// 		    7:chair

	int table[12][8] = {
		{1,1,1,1,1,1,1,1}, // VIP#1
		{1,1,1,0,1,1,0,1},
		{1,1,1,0,1,1,0,1},
		{1,1,1,0,1,1,0,1},
		{1,1,1,0,1,1,0,1},
		{1,1,1,0,1,1,0,1},
		{1,1,1,1,1,1,1,1}, // VIP#2
		{1,1,1,0,1,1,0,1},
                {1,1,1,0,1,1,0,1},
                {1,1,1,0,1,1,0,1},
                {1,1,1,0,1,1,0,1},
                {1,1,1,0,1,1,0,1}
		};
	table[4][7] +=1; // 5th place on row 1 = [4], chair is [7]
	table[8][1] -=1; // 3rd place on row 2 = [8], spoon is [1]
	table[0][1] -=1; // VIP = [0], spoon is [1],
	table[8][1] +=1; // 3rd place on row 2 = [8], spoon is [1]
	table[0][6] -=1; // VIP without spoon is [0], dessert plate = [6]
	
	return 0;	
}
