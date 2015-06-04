/*
= Brainfuck

If you have gcc:

----
g++ -o brainfuck.exe brainfuck.cpp
brainfuck.exe helloworld.bf
----
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <String.h>

using namespace std;

/**
 * Primitive Brainfuck commands
 */
typedef enum { 
    INCREMENT, // +
    DECREMENT, // -
    SHIFT_LEFT, // <
    SHIFT_RIGHT, // >
    INPUT, // ,
    OUTPUT, // .
	ZERO // 0
} Command;

// Forward references. Silly C++!
class CommandNode;
class Loop;
class Program;

/**
 * Visits?!? Well, that'd indicate visitors!
 * A visitor is an interface that allows you to walk through a tree and do stuff.
 */
class Visitor {
    public:
        virtual void visit(const CommandNode * leaf) = 0;
        virtual void visit(const Loop * loop) = 0;
        virtual void visit(const Program * program) = 0;
};

/**
 * The Node class (like a Java abstract class) accepts visitors, but since it's pure virtual, we can't use it directly.
 */
class Node {
    public:
        virtual void accept (Visitor *v) = 0;
};

/**
 * CommandNode publicly extends Node to accept visitors.
 * CommandNode represents a leaf node with a primitive Brainfuck command in it.
 */
class CommandNode : public Node {
    public:
        Command command;
		int count;
        CommandNode(char c, int n) {
            switch(c) {
                case '+': command = INCREMENT; break;
                case '-': command = DECREMENT; break;
                case '<': command = SHIFT_LEFT; break;
                case '>': command = SHIFT_RIGHT; break;
                case ',': command = INPUT; break;
                case '.': command = OUTPUT; break;
				case '0': command = ZERO; break;
            }
			count = n;
        }
        void accept (Visitor * v) {
            v->visit(this);
        }
};

class Container: public Node {
    public:
        vector<Node*> children;
        virtual void accept (Visitor * v) = 0;
};

/**
 * Loop publicly extends Node to accept visitors.
 * Loop represents a loop in Brainfuck.
 */
class Loop : public Container {
    public:
        void accept (Visitor * v) {
            v->visit(this);
        }
};

/**
 * Program is the root of a Brainfuck program abstract syntax tree.
 * Because Brainfuck is so primitive, the parse tree is the abstract syntax tree.
 */
class Program : public Container {
    public:
        void accept (Visitor * v) {
            v->visit(this);
        }
};

/* 
----------------------------------------------
Ashley's Stuff
----------------------------------------------
*/


/**
 * Read in the file by recursive descent.
 * Modify as necessary and add whatever functions you need to get things done.
 */
void parse(fstream & file, Container * container) {
    char c;
	int count = 1;
	Loop *loopContainer;

	while(file >> c) {
		
		// MAKE SURE TO RESET THE COUNTER ON THE NEXT PASS
		count = 1;

		// while the next peeking character is the same then continue to move along the input
		// until a different character is found and kepe track of the count of the same number of symbols
		while(((char)file.peek()) == c)
		{
			count++;
			file >> c;
		}

		switch(c) {
			case '[' :
				loopContainer = new Loop();
				parse(file, loopContainer);
				// check the loopConatiner I get back to see if it's [+] or [-]
				if(loopContainer->children.size() == 1 )
					{
						// since we modified the command nodes to hold counts we must make sure its a count of 1
						// need to cast node to commandnode!
							CommandNode *child = (CommandNode *) loopContainer->children.front();
						if((child->command==INCREMENT || child->command==DECREMENT )&& child->count == 1){
							container->children.push_back(new CommandNode('0', 1));
						}
						else {
							// make sure to stick back any loops that aren't +,- like <,> and such
							container->children.push_back(loopContainer);
						}

				}
				else {
					container->children.push_back(loopContainer);
				}
				break;
			case ']' : 
				return;
            case '+': 
            case '-': 
            case '<': 
            case '>': 
            case ',':
            case '.': 
				container->children.push_back(new CommandNode(c, count)); 
				break;
        }
	}

}

class Interpreter : public Visitor {
    char memory[30000];
    int pointer;
    public:
        void visit(const CommandNode * leaf) {
			for(int a = 0; a < leaf->count; a++) {
				switch (leaf->command) {
					case INCREMENT:
						memory[pointer]++;
						break;
					case DECREMENT:
						memory[pointer]--;
						break;
					case SHIFT_LEFT:
						pointer--;
						break;
					case SHIFT_RIGHT:
						pointer++;
						break;
					case INPUT:
						cin.get(memory[pointer]);
						break;
					case OUTPUT:
						cout<<memory[pointer];
						break;
					case ZERO:
						memory[pointer] = 0;
						break;
				}
			}
        }
        void visit(const Loop * loop) {
			while(memory[pointer]!=0) {
				for (vector<Node*>::const_iterator it = loop->children.begin(); it != loop->children.end(); ++it) {
					(*it)->accept(this);
				}
			}
        }
        void visit(const Program * program) {
            // zero init the memory array
			memset(memory, 0, 30000); 

            // set pointer to zero
			pointer = 0;

            for (vector<Node*>::const_iterator it = program->children.begin(); it != program->children.end(); ++it) {
                (*it)->accept(this);
            }
        }
};

/**
 * A printer for Brainfuck abstract syntax trees.
 * As a visitor, it will just print out the commands as is.
 * For Loops and the root Program node, it walks through all the children.
 */
class Printer : public Visitor {
    public:
        void visit(const CommandNode * leaf) {
			for(int a = 0; a < leaf->count; a++) {
	            switch (leaf->command) {
					case INCREMENT:   cout << '+'; break;
					case DECREMENT:   cout << '-'; break;
					case SHIFT_LEFT:  cout << '<'; break;
					case SHIFT_RIGHT: cout << '>'; break;
					case INPUT:       cout << ','; break;
					case OUTPUT:      cout << '.'; break;
					case ZERO:		  cout << "[+]"; break;
				}
			}
        }
        void visit(const Loop * loop) {
            cout << '[';
            for (vector<Node*>::const_iterator it = loop->children.begin(); it != loop->children.end(); ++it) {
                (*it)->accept(this);
            }
            cout << ']';
        }
        void visit(const Program * program) {
            for (vector<Node*>::const_iterator it = program->children.begin(); it != program->children.end(); ++it) {
                (*it)->accept(this);
            }
            cout << '\n';
        }
};

/**
 * A compiler for Brainfuck abstract syntax trees.
 * As a visitor, it will just print out the commands as is.
 * For Loops and the root Program node, it walks through all the children.
 */
class JavaCompiler : public Visitor {
    public:
        void visit(const CommandNode * leaf) {
            switch (leaf->command) {
                case INCREMENT:   cout << "arr[arrayIndex]+="<<leaf->count<<";\n"; break;
                case DECREMENT:   cout << "arr[arrayIndex]-="<<leaf->count<<";\n"; break;
                case SHIFT_LEFT:  cout << "arrayIndex-="<<leaf->count<<";\n"; break;
                case SHIFT_RIGHT: cout << "arrayIndex+="<<leaf->count<<";\n"; break;
                case INPUT:       
								for(int a = 0; a < leaf->count; a++) {
									cout << "arr[arrayIndex] = reader.next().charAt(0);\n"; 
								}
								break;
                case OUTPUT:      
								for(int a = 0; a < leaf->count; a++) {
									cout << "System.out.print(arr[arrayIndex]);\n";
								}
								 break;
				case ZERO:		cout << "arr[arrayIndex]=0;\n"; break;
            }
        }
        void visit(const Loop * loop) {
            cout << "while(arr[arrayIndex]!=0) {\n";
            for (vector<Node*>::const_iterator it = loop->children.begin(); it != loop->children.end(); ++it) {
                (*it)->accept(this);
            }
			cout << "}\n";
        }
        void visit(const Program * program) {
			cout << "import java.util.Scanner;\n";
			cout << "public class ashleyworld {\n";
			cout << "public static void main(String[] args) {\n";
			cout << "Scanner reader = new Scanner(System.in);\n";
			cout << "char[] arr = new char[30000];\n";
			cout << "int arrayIndex = 0;\n";
            for (vector<Node*>::const_iterator it = program->children.begin(); it != program->children.end(); ++it) {
                (*it)->accept(this);
            }
			cout << "}\n";
			cout << "}\n";
        }
};


int main(int argc, char *argv[]) {
    fstream file;
    Program program;
    Printer printer;
    Interpreter interpreter;
	JavaCompiler javacompiler;
    if (argc == 1) {
        cout << argv[0] << ": No input files." << endl;
    } else if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            file.open(argv[i], fstream::in);
            parse(file, & program);
           // program.accept(&printer);
           // program.accept(&interpreter);
	       program.accept(&javacompiler);
            file.close();
        }
    }
}