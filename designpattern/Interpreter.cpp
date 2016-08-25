#include <iostream>
#include <string>

using namespace std;

#ifdef NORMAL
class Thousand;
class Hundred;
class Ten;
class One;

class RNInterpreter {
    public:
        RNInterpreter();
        RNInterpreter(int) {}
        int interpret(char*);
        virtual void interpret(char* input, int& total) {
            int index = 0;

            if (!strncmp(input, nine(), 2)) {
                total += 9 * multiplier();
                index += 2;
            }
            else if (!strncmp(input, four(), 2)) {
                total += 4 * multiplier();
                index += 2;
            }
            else {
                if (input[0] == five()) {
                    total += 5 * multiplier();
                    index = 1;
                }
                else {
                    index = 0;
                }

                for (int end = index + 3; index < end; ++index) {
                    if (input[index] == one()) {
                        total += 1 * multiplier();
                    }
                    else {
                        break;
                    }
                }
            }

            strcpy(input, &(input[index]));
        }

    protected:
        virtual char one() {}
        virtual char *four() {}
        virtual char five() {}
        virtual char *nine() {}
        virtual int multiplier() {}

    private:
        RNInterpreter* thousands;
        RNInterpreter* hundreds;
        RNInterpreter* tens;
        RNInterpreter* ones;
};

class Thousand: public RNInterpreter {
    public:
        Thousand(int): RNInterpreter(1) {}

    protected:
        char one() {
            return 'N';
        }

        char* four() {
            return "";
        }

        char five() {
            return '\0';
        }

        char *nine() {
            return "";
        }

        int multiplier() {
            return 1000;
        }
};

class Hundred: public RNInterpreter {
    public:
        Hundred(int): RNInterpreter(1) {}
        
    protected:
        char one() {
            return 'C';
        }

        char *four() {
            return "CD";
        }

        char five() {
            return 'D';
        }

        char *nine() {
            return "CM";
        }

        int multiplier() {
            return 100;
        }
};

class Ten: public RNInterpreter {
    public:
        Ten(int): RNInterpreter(1) {}

    protected:
        char one() {
            return 'X';
        }

        char *four() {
            return "XL";
        }

        char five() {
            return 'L';
        }

        char *nine() {
            return "XC";
        }

        int multiplier() {
            return 10;
        }
};

class One: public RNInterpreter {
    public:
        One(int): RNInterpreter(1) {}

    protected:
        char one() {
            return 'I';
        }

        char *four() {
            return "IV";
        }

        char five() {
            return 'V';
        }

        char *nine() {
            return "IX";
        }

        int multiplier() {
            return 1;
        }
};

RNInterpreter::RNInterpreter() {
    thousands = new Thousand(1);
    hundreds = new Hundred(1);
    tens = new Ten(1);
    ones = new One(1);
}

int RNInterpreter::interpret(char *input) {
    int total = 0;
    thousands->interpret(input, total);
    hundreds->interpret(input, total);
    tens->interpret(input, total);
    ones->interpret(input, total);

    if (strcmp(input, "")) {
        return 0;
    }

    return total;
}

int main() {
    RNInterpreter interpreter;
    char input[20];
    cout << "Enter Roman Numeral: ";

    while (cin >> input) {
        cout << "    interpretation is " << interpreter.interpret(input) << endl;
        cout << "Enter Roman Numberal: ";
    }
}
#endif
