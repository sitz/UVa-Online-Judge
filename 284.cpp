#include <bits/stdc++.h>

using namespace std;

// @ http://algoshare.blogspot.sg/2012/08/284-logic.html
// the code uses several global variables for the reason that i created a debug function, print_array(), to aid me in checking the code prior to submission, to see whether the code actually does what it is intended to do. instead of passing the arrays as arguments to the print_arrays() function, i thought it would be easier to use global variables. using global variables is not good programming practice. however, since we are after performance and not beauty or maintainability, i thought it would be all write to deviate from good programming habits.

// first, i explain the data structures used. several array variables are utilized. in the real world, one would not do this to implement the algorithm to this problem. in the real world, one would probably use object-oriented programming and classes to implement the algorithm. however, once again, as the emphasis of uva problems is speed rather than beauty, i resorted to this rather ugly but probably faster code implementation.

// the problem specifies a 10x10 grid array where each element or node in the grid corresponds to an input node, output node, not gate, and gate, or or gate. we could have used a two-dimensional array to implement the code; however, it would probably easier to reduce and think of the problem in terms of only one dimension to simplify things. after all, every node in the 10x10 grid two-dimensional array would correspond to a unique element in a 100-element one-dimensional array. for instance the node [9][8] in the 2d array would correspond to node [98] in the 1d array, and node [0][0] in the 2d array would correspond to node [0] in the 1d array.

// in object-oriented programming, a node would correspond to a class with several variables in it. the class would have a variable corresponding to the symbol of the node, which can be i, o, &, | or !, depending whether the node is an input, output, and, or or not gate. in addition, the class would have a variable corresponding to the x-coordinate of the node, and another variable corresponding to the y-coordinate of the node. moreover, the class would have one or two inputs depending on what type of gate it is. if the node is an input, output or not gate, then the node would only have one input. if the node, however, were an and gate or an or gate, then it would require two input variables. finally, the class would need an output variable to store the output of a gate.

// the gates referred to in this problem are digital electronic gates which are very common in electronics. they are often called logic gates and are implemented using transistors. these gates can be very tiny and are almost always present inside most electronic devices such as laptops, televisions and cellphones. you may read more about logic gates in the wikipedia. i guess the most important aspect of a gate is the truth table which is a table which lists down all possible input combinations and the corresponding output values.

// in the code below, no classes are used and we did not use a linked-list of class nodes or a similar data structure to store the nodes. instead, the maximum number of nodes are pre-allocated. the maximum number of nodes is 100 since a 10x10 grid would have 100 nodes. one would think that this is a waste of memory resources since we are pre-allocating 100 nodes immediately when in fact maybe just a few nodes are needed. this argument is true; however, remember that we are after speed and not beauty or maintainability. since 100 is not that large a number, pre-allocating them immediately may be faster than using some other complex data structure that allocates the exact number of nodes needed. using a complex data structure may be more efficient in using memory resources; however, the added complexity will inevitably slow things down.

//  though no classes are actually used, the concept of classes is somewhat indirectly embedded within the code. each node is represented by an index alignment of several array variables. for instance, the node with an x-coordinate of 9 and a y-coordinate of 8 is represented by the elements with index 98 of the arrays arr_v, arr_s, arr_a and arr_c. array arr_s is for storing the symbol and elements in it can have values of i, o, &, | or !. array arr_v is for storing the calculated output of the nodes. if for example, node 98 is an and gate, then arr_v[98] would correspond to the output of an and gate.

// array arr_a stores the input arguments of the gate in reference form. arr_a is a 2d array and each node can have up to a maximum of two input arguments. if node 98 is an and gate that takes as its inputs the output of nodes 72 and 25, then arr_a[98][0] and arr_a[98][1] would have the values 72 and 25. it should be noted that the code is written in such a way that arr[98][0] could have a value of 72 and arr[98][1] a value of 25, or vice-versa. the order in which 72 and 25 are stored does not matter. similarly, a real and gate will not mind the order in which its inputs are applied. a two-input and gate can take a 1 in its first input and a 0 in its second input, and output a 0 based on these inputs. if a 0 were input in its first input and a 1 in its second input, the output will still be 0. so, the ordering does not really matter, and we actually use this fact to optimize the code, as will be explained in a while.

// the array arr_c is used in relation to arr_a. each node in arr_a has two elements corresponding to the input arguments of a given gate. for instance, the input arguments to node 98 are placed in the slots, arr_a[98][0] and arr_a[98][1]. arr_c is used to take note of the next slot to store an input argument. ideally, arr_c should only store 0 or 1 values which would tell us whether to store an input argument into arr_a[98][0] or arr_a[98][1] for the case of gate 98. however, in order to save time, and avoid having to initialize all the elements in arr_c to 0 before testing each test case, we simply use the least significant bit of every element in arr_c.

// the least significant bit of any number would be 0 or 1 at any given time. for instance, the number 7 would be presented in binary as 0b0111 and its least significant bit (lsb) would be 1. in this case, if we were to store an input argument for node 98, then we would store it in arr_a[98][1]. we then increment the number 7 by 1 to obtain 8, which in binary is 0b1000. now, the least significant bit is 0, so storing another input argument to node 98 would be done in arr_a[98][0]. the protocol used in this code is to increment arr_c[98] whenever a new argument is stored in arr_a[98][i], where is either 0 or 1. to obtain the last input argument stored into arr_a[98], we then simply subtract 1 from arr_c[98]. if, for example, arr_c[98] has a value of 8, then to obtain the last input argument stored into arr_a[98], we simply subtract 1 from 8 to obtain 7, and then obtain the least significant bit of 7 which is 1. as 1 is obtained, then the last input argument stored for node 98 is found in arr_a[98][1].

// obtaining the lsb of a number can be done efficiently by bit-wise anding the number with 1. for instance to get the lsb of the number 7, we can simply bit-wise and 7 with 1 to obtain 1. in binary form, this would be represented as:

// 0d7: 0b0111
// 0d1: 0b0001
// ===========
// 0d1: 0b0001

// in bit-wise anding, the result will only be 1 if the inputs are both 1. in this case, as the lsb's of both 7 and 1 are both 1, then the result is 1, which is the lsb of 7.

// we have explained the arrays, arr_v, arr_a, arr_c. now, we explain array, arr_r. arr_r lists all the nodes present in a given circuit. in the example given in the problem specification, arr_r would have the values: 0, 2, 11, 21, 13, and 23. these values correspond to the first column of the program inputs:

// 00i 11 13 ..
// 02i 11 13 ..
// 11& 21 ..
// 21o ..
// 13| 23 ..
// 23o ..

// arr_i is used to store the nodes that correspond to input gates. in the example of the problem specification, arr_i would contain 0 and 2. lastly, arr_o is used to store the nodes corresponding to output gates. in the problem example, arr_o would contain gates 21 and 23.

// once all program inputs are encoded into the arrays, the program starts working by first doing some initialization for each test case for a given circuit. initialization is done by setting all nodes in arr_v that are listed in arr_r to -1 to indicate unknown gate output values (lines 123-125). the following screen output shows the values of the arrays after this initialization of arr_v:

// arr_i : 00 02
// arr_o : 21 23
// arr_r : 00 02 11 21 13 23
// arr_v : -1 -1 -1 -1 -1 -1
// arr_s :  i  i  &  o  |  o
// arr_c : 00 00 00 01 00 01
// arr_a0: 00 00 00 11 00 13
// arr_a1: 00 00 02 00 02 00

// notice that arr_i contains the input gates of the circuit, which are 00 and 02. arr_o contains the output gates, 21 and 23. arr_r lists all the gates present in the circuit. for the rest of the arrays, print_arrays() prints the elements with indices sourced from arr_r. for instance, arr_v lists the values of its elements with indices 0, 2, 11, 21, 13, 23. these indices are found in arr_r. arr_s lists the symbols stored in its elements with indices 0, 2, 11, 21, 13, and 23. using the output of print_arrays(), we can see that node 11 is an and gate that takes as its inputs the outputs of nodes 00 and 02. similarly, node 21 is an output gate that takes as its input the output of node 11. for node 21, notice that arr_c[21] has a value of 01. this means that the last input argument for node 21 was stored in arr_a[21][1-1] which is arr_a[21][0]. remember that arr_c[x] takes note of the next position in arr_a[x][i] to store an input argument for node x in, whether in arr_a[x][0] or in arr_a[x][1].

// after initializing arr_v to -1 values to indicate unknown output values, we initialize arr_v with the inputs as specified by the test case (lines 130-132). for the first test case, 00, in the problem specification, the output of print_arrays() will show the following upon input initialization:

// arr_i : 00 02
// arr_o : 21 23
// arr_r : 00 02 11 21 13 23
// arr_v :  0  0 -1 -1 -1 -1
// arr_s :  i  i  &  o  |  o
// arr_c : 00 00 00 01 00 01
// arr_a0: 00 00 00 11 00 13
// arr_a1: 00 00 02 00 02 00

// notice that gates 0 and 2 now have output values of 0 and 0.

// next, we iterate through the nodes, attempting to calculate the output values for each of the nodes. if a node in arr_v has a value of -1, then it means that the output value of that node is unknown, and so we try to calculate for it. if can be calculated, then we convert the output value from unknown to the calculated value. if the unknown output value of a given gate cannot be calculated because the output values of another gate to which it is connected to is also unknown, then we simply move on to the next gate. we keep iterating through the nodes until all output values of all gates are no longer unknown; that is arr_v does not contain any -1 values anymore (lines 134-178).

// let us view the output of print_arrays() every time there is an update in one of the values in arr_v:

// arr_i : 00 02
// arr_o : 21 23
// arr_r : 00 02 11 21 13 23
// arr_v :  0  0  0 -1 -1 -1
// arr_s :  i  i  &  o  |  o
// arr_c : 00 00 00 01 00 01
// arr_a0: 00 00 00 11 00 13
// arr_a1: 00 00 02 00 02 00
// notice above that the output value of gate 11 changes since now, the output values of gates 0 and 2, which are inputs to gate 11, are now known.
// arr_i : 00 02
// arr_o : 21 23
// arr_r : 00 02 11 21 13 23
// arr_v :  0  0  0  0 -1 -1
// arr_s :  i  i  &  o  |  o
// arr_c : 00 00 00 01 00 01
// arr_a0: 00 00 00 11 00 13
// arr_a1: 00 00 02 00 02 00
// since the output of gate 11 is connected to gate 21 which is an output gate, and since gate 11 has value of 0, then gate 21 gains an output value of 0.
// arr_i : 00 02
// arr_o : 21 23
// arr_r : 00 02 11 21 13 23
// arr_v :  0  0  0  0  0 -1
// arr_s :  i  i  &  o  |  o
// arr_c : 00 00 00 01 00 01
// arr_a0: 00 00 00 11 00 13
// arr_a1: 00 00 02 00 02 00
// since gate 13 is an or gate and since its two inputs have values of both 0, then gate 13 obtains an output value of 0. an or gate will output a 1 if at least one of its inputs is 1. in this case, however, both inputs into the or gate are 0, so the output is 0.
// arr_i : 00 02
// arr_o : 21 23
// arr_r : 00 02 11 21 13 23
// arr_v :  0  0  0  0  0  0
// arr_s :  i  i  &  o  |  o
// arr_c : 00 00 00 01 00 01
// arr_a0: 00 00 00 11 00 13
// arr_a1: 00 00 02 00 02 00
// since gate 13 is connected to gate 23, which is an output gate, then gate 23 obtains a value of 0 as well. once all output values are obtained, we print the output values of the output gates (lines 180-182).

char arr_s[100];
int num_nodes, num_i, num_o, arr_i[100], arr_o[100], arr_r[100], arr_v[100], arr_a[100][2], arr_c[100];

void print_arrays()
{
	int j, k;

	printf("arr_i : ");
	for (j = 0; j < num_i; j += 1)
	{
		printf("%02d ", arr_i[j]);
	}
	printf("\n");
	printf("arr_o : ");
	for (j = 0; j < num_o; j += 1)
	{
		printf("%02d ", arr_o[j]);
	}
	printf("\n");
	printf("arr_r : ");
	for (j = 0; j < num_nodes; j += 1)
	{
		printf("%02d ", arr_r[j]);
	}
	printf("\n");
	printf("arr_v : ");
	for (j = 0; j < num_nodes; j += 1)
	{
		k = arr_v[arr_r[j]];
		printf("%2d ", k);
	}
	printf("\n");
	printf("arr_s : ");
	for (j = 0; j < num_nodes; j += 1)
	{
		printf(" %c ", arr_s[arr_r[j]]);
	}
	printf("\n");
	printf("arr_c : ");
	for (j = 0; j < num_nodes; j += 1)
	{
		printf("%02d ", arr_c[arr_r[j]] & 1);
	}
	printf("\n");
	printf("arr_a0: ");
	for (j = 0; j < num_nodes; j += 1)
	{
		printf("%02d ", arr_a[arr_r[j]][0]);
	}
	printf("\n");
	printf("arr_a1: ");
	for (j = 0; j < num_nodes; j += 1)
	{
		printf("%02d ", arr_a[arr_r[j]][1]);
	}
	printf("\n\n");
}

int main()
{
	char line[100], ctmp[100];
	char *pch;
	int n, t, node, curr_node, curr_arg, num_unk;
	int arg_a, arg_b;
	int i, j, k;
	char symbol;

	fgets(line, 100, stdin);
	sscanf(line, "%d", &n);

	for (i = 0; i < n; i += 1)
	{
		num_nodes = 0;
		num_i = 0;
		num_o = 0;

		while (1)
		{
			fgets(line, 100, stdin);
			pch = strtok(line, " \t");

			if (pch[0] == 'e')
			{
				break;
			}

			ctmp[0] = pch[0];
			ctmp[1] = pch[1];
			ctmp[2] = 0;
			curr_node = atoi(ctmp);
			arr_r[num_nodes] = curr_node;
			num_nodes += 1;

			symbol = pch[2];
			arr_s[curr_node] = symbol;
			if (symbol == 'i')
			{
				arr_i[num_i] = curr_node;
				num_i += 1;
			}
			else if (symbol == 'o')
			{
				arr_o[num_o] = curr_node;
				num_o += 1;
			}

			pch = strtok(NULL, " \t");
			while (pch != NULL)
			{
				if (pch[0] == '.')
				{
					break;
				}

				node = atoi(pch);
				curr_arg = arr_c[node] & 1;
				arr_a[node][curr_arg] = curr_node;
				arr_c[node] += 1;

				pch = strtok(NULL, " \t");
			}
		}

		fgets(line, 100, stdin);
		sscanf(line, "%d", &t);

		for (j = 0; j < t; j += 1)
		{
			for (k = 0; k < num_nodes; k += 1)
			{
				arr_v[arr_r[k]] = -1;
			}

			fgets(line, 100, stdin);
			pch = strtok(line, " \t");

			for (k = 0; k < num_i; k += 1)
			{
				arr_v[arr_i[k]] = (pch[k] == 48 ? 0 : 1);
			}

			while (1)
			{
				num_unk = 0;

				for (k = 0; k < num_nodes; k += 1)
				{
					node = arr_r[k];

					if (arr_v[node] == -1)
					{
						symbol = arr_s[node];

						arg_a = arr_v[arr_a[node][(arr_c[node] - 1) & 1]];

						if (arg_a == -1)
						{
							num_unk += 1;
							continue;
						}

						if (symbol == '!')
						{
							arr_v[node] = (arg_a == 0 ? 1 : 0);
							continue;
						}
						else if (symbol == 'o')
						{
							arr_v[node] = arg_a;
							continue;
						}

						arg_b = arr_v[arr_a[node][arr_c[node] & 1]];

						if (arg_b == -1)
						{
							num_unk += 1;
							continue;
						}

						if (symbol == '&')
						{
							arr_v[node] = arg_a & arg_b;
						}
						else
						{
							arr_v[node] = arg_a | arg_b;
						}
					}
				}

				if (num_unk <= 0)
				{
					break;
				}
			}

			for (k = 0; k < num_o; k += 1)
			{
				printf("%d", arr_v[arr_o[k]]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
