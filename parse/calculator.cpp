#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define eps 0.0001
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int ll
#define MIN -2147483648
#define MAX (MIN * (-1) + 100)
#define MOD 1000000007

using namespace std;

typedef long long ll;

enum Token_value : char {
    NAME,       NUMBER,     END,
    PLUS='+',   MINUS='-',  MUL='*',    DIV='/',
    PRINT=';',  ASSIGN='=', LP='(',     RP = ')'
};

enum Number_value : char {
    NUM0 = '0',     NUM1 = '1',     NUM2 = '2',
    NUM3 = '3',     NUM4 = '4',     NUM5 = '5',
    NUM6 = '6',     NUM7 = '7',     NUM8 = '8',
    NUM9 = '9',     NUMP = '.'
};

Token_value curr_tok = PRINT;
double number_value;
string string_value;
map< string, double > table;
int no_of_errors;

double expr(istream*, bool);

double error(const string & error_message) {
    ++no_of_errors;
    cerr << "error: " << error_message << endl;
    return 1;
}

Token_value get_token(istream * input){
    char ch;
    do {
        if (!input->get(ch)) {
            return curr_tok = END;
        }
    } while (ch != endl && isspace(ch));
    
    switch (ch) {
        case 0:
            return curr_tok = END;
        case PRINT:
        case endl:
            return curr_tok = PRINT;
        case MUL:
        case DIV:
        case PLUS:
        case MINUS:
        case LP:
        case RP:
        case ASSIGN:
            return curr_tok = Token_value(ch);
        case NUM0: case NUM1: case NUM3: case NUM4: case NUM5:
        case NUM6: case NUM7: case NUM8: case NUM9: case NUM2:
        case NUMP:
            input->putback(ch);
            *input >> number_value;
            return curr_tok = NUMBER;
        default:
            if (isalpha(ch)) {
                string_value = ch;
                while (input->get(ch) && isalnum(ch)) {
                    string_value.push_back(ch);
                }
                input->putback(ch);
                return curr_tok = NAME;
            }
            error("Bad Token");
            return curr_tok = PRINT;
    }
}

double prim(istream * input, bool get) {
    if (get) {
        get_token(input);
    }
    
    switch (curr_tok) {
        case NUMBER: {
            double v = number_value;
            get_token(input);
            return v;
        }
        case NAME: {
            double & v = table[string_value];
            if (get_token(input) == ASSIGN) {
                v = expr(input, true);
            }
            return v;
        }
        case MINUS: {
            return -prim(input, true);
        }
        case LP: {
            double e = expr(input, 1);
            if (curr_tok != RP) {
                return error("')' expected");
            }
            get_token(input);
            return e;
        }
        default: {
            return error("primary expected");
        }
    }
}

double term(istream * input, bool get) {
    double left = prim(input, get);
    for ( ; ; ) {
        switch (curr_tok) {
            case MUL: {
                left *= prim(input, true);
                break;
            }
            case DIV: {
                if (double d = prim(input, true)) {
                    left /= d;
                    break;
                }
                return error("Divide by 0");
            }
            default:
                return left;
        }
    }
}

double expr(istream * input, bool get) {
    double left = term(input, true);
    for ( ; ; ) {
        switch (curr_tok) {
            case PLUS: {
                left += term(input, true);
                break;
            }
            case MINUS: {
                left -= term(input, true);
                break;
            }
            default: {
                return left;
            }
        }
    }
}


int main(int argc, char* argv[]) {
    srand((unsigned int)time(NULL));
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/Documents/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/macbook/Documents/cpp/cpp/output.txt", "w", stdout);
#else
    //    freopen("grasshopper.in", "r", stdin);
    //    freopen("grasshopper.out", "w", stdout);
#endif
    istream * input = nullptr;
    
    switch (argc) {
        case 1:
            input = &std::cin;
            break;
        case 2:
            input = new std::istringstream(argv[1]);
            break;
        default:
            error("Too many arguments");
            return 1;
    }

    while (*input) {
        get_token(input);
        if (curr_tok == END) {
            break;
        }
        if (curr_tok == PRINT) {
            continue;
        }
        cout << expr(input, false) << endl;
    }
    if (input != &cin) {
        delete input;
    }
    
    return no_of_errors;
}









