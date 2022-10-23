#include "stack.h"

using namespace std;

void printResults(Stack& modelStack, Stack& moddedStack);
void populateTwoStacks(Stack& larger, Stack& smaller);
void copyTest();
void assignLargerToSmaller();
void assignSmallerToLarger();
void assignEqualSize();
void assigningOneEmpty();
void assignToItself();
void runFunction1(Stack stack);
void runFunction2(Stack& stack);
void testCopyAndAssignment();
void gdbTest();

int main()
{
    testCopyAndAssignment();
   // gdbTest();
	return 0;
}

void testCopyAndAssignment(){
    copyTest();
	assignLargerToSmaller();
	assignSmallerToLarger();
	assignEqualSize();
	assigningOneEmpty();
	assignToItself();
    }

void copyTest()
{
	cout << "Copying stack test" << endl;
	Stack s1;
	for (int i = 0; i < INITIAL_SIZE - 1; i++) {
		s1.push(i);
	}

	Stack s2(s1);
	printResults(s1, s2);
}

void populateTwoStacks(Stack& larger, Stack& smaller)
{
	for (int i = 0; i < INITIAL_SIZE  + 2; i++) {
		larger.push(i);
	}
	for (int i = 0; i < INITIAL_SIZE - 1; i++) {
		smaller.push(i);
	}
}

void printResults(Stack& modelStack, Stack& moddedStack)
{
	cout << "Model stack: " << endl;
	modelStack.printStack();
	cout << "Modified stack: " << endl;
	moddedStack.printStack();
	cout << endl;
}

void assignLargerToSmaller()
{
	cout << "Assigning larger to smaller test" << endl;
	Stack larger, smaller;
	cout << "before:" << endl;
	populateTwoStacks(larger, smaller);
	printResults(larger, smaller);
	smaller = larger;
	cout << "after:" << endl;
	printResults(larger, smaller);
}

void assignSmallerToLarger()
{
	cout << "Assigning smaller to larger test" << endl;
	Stack larger, smaller;
	cout << "before:" << endl;
	populateTwoStacks(larger, smaller);
	printResults(smaller, larger);
	larger = smaller;
	cout << "after:" << endl;
	printResults(smaller, larger);
}

void assignEqualSize()
{
	cout << "Assigning stacks of equal size" << endl;
	Stack s1, s2;
	for (int i = 0; i < INITIAL_SIZE; i++) {
		s1.push(i);
		s2.push(INITIAL_SIZE - i);
	}
	cout << "before:" << endl;
	printResults(s1, s2);
	s2 = s1;
	cout << "after:" << endl;
	printResults(s1, s2);
}

void assigningOneEmpty()
{
	cout << "Assigning empty stack to stack with elements:" << endl;
	Stack nonEmpty, empty;
	for (int i = 0; i < INITIAL_SIZE; i++) {
		nonEmpty.push(i);
	}
	cout << "before:" << endl;
	printResults(empty, nonEmpty);
	nonEmpty = empty;
	cout << "after:" << endl;
	printResults(empty, nonEmpty);
}

void assignToItself()
{
	cout << "assigning stack to itself test" << endl;
	Stack s1;
	for (int i = 0; i < INITIAL_SIZE; i++) {
		s1.push(i);
	}
	cout << "before:" << endl;
	printResults(s1, s1);
	s1 = s1;
	cout << "after:" << endl;
	printResults(s1, s1);
}

void gdbTest()
{
	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);

	Stack s2(s1);

	Stack s3 = s1;

	Stack s4;
	s4.push(10);
	s4 = s1;

	runFunction1(s1); 
	runFunction2(s1);
}

void runFunction1(Stack stack){
    stack.printStack();
    }
void runFunction2(Stack& stack){
    stack.printStack();
    }

