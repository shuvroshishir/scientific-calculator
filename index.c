#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <windows.h>

#define MAX 100
#define PI 3.14159265358979323846

// UI Functions
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void showUI()
{
    system("cls");

    setColor(11); // Cyan
    printf("\n=====================================\n");
    printf("      SCIENTIFIC CALCULATOR\n");
    printf("=====================================\n");

    setColor(14); // Yellow
    printf("\nSupported Operations:\n");

    setColor(10); // Green
    printf("  Basic: +  -  *  /\n");
    printf("  Functions: sin(x), cos(x), tan(x)\n");
    printf("             log(x), sqrt(x)\n");

    setColor(8); // Gray
    printf("\nExample: sin(30) + 5 * 2\n");

    printf("\n-------------------------------------\n");

    setColor(15); // White
}

double numStack[MAX];
int numTop = -1;

char opStack[MAX];
int opTop = -1;

void pushNum(double val)
{
    numStack[++numTop] = val;
}

double popNum()
{
    return numStack[numTop--];
}

void pushOp(char op)
{
    opStack[++opTop] = op;
}

char popOp()
{
    return opStack[opTop--];
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            printf("Error: Division by zero\n");
            exit(1);
        }
        return a / b;
    }
    return 0;
}

// Scientific functions
double applyFunction(char *func, double val)
{
    if (strcmp(func, "sin") == 0)
        return sin(val * PI / 180);
    if (strcmp(func, "cos") == 0)
        return cos(val * PI / 180);
    if (strcmp(func, "tan") == 0)
        return tan(val * PI / 180);
    if (strcmp(func, "log") == 0)
        return log10(val);
    if (strcmp(func, "sqrt") == 0)
        return sqrt(val);

    printf("Unknown function: %s\n", func);
    exit(1);
}

double evaluate(char *exp)
{
    int i = 0;

    while (exp[i])
    {

        if (exp[i] == ' ')
        {
            i++;
            continue;
        }

        // Number (including decimal)
        if (isdigit(exp[i]) || exp[i] == '.')
        {
            double val = 0;
            double decimal = 0.1;
            int isDecimal = 0;

            while (isdigit(exp[i]) || exp[i] == '.')
            {
                if (exp[i] == '.')
                {
                    isDecimal = 1;
                    i++;
                    continue;
                }

                if (!isDecimal)
                {
                    val = val * 10 + (exp[i] - '0');
                }
                else
                {
                    val = val + (exp[i] - '0') * decimal;
                    decimal *= 0.1;
                }
                i++;
            }
            pushNum(val);
            i--;
        }

        // Function (sin, cos, log, etc.)
        else if (isalpha(exp[i]))
        {
            char func[10];
            int j = 0;

            while (isalpha(exp[i]))
            {
                func[j++] = exp[i++];
            }
            func[j] = '\0';

            if (exp[i] == '(')
                i++;

            char innerExp[MAX];
            int k = 0;
            int bracket = 1;

            while (bracket > 0)
            {
                if (exp[i] == '(')
                    bracket++;
                if (exp[i] == ')')
                    bracket--;

                if (bracket > 0)
                    innerExp[k++] = exp[i];

                i++;
            }
            innerExp[k] = '\0';

            double val = evaluate(innerExp);
            double result = applyFunction(func, val);

            pushNum(result);
            i--;
        }

        else if (exp[i] == '(')
        {
            pushOp(exp[i]);
        }

        else if (exp[i] == ')')
        {
            while (opStack[opTop] != '(')
            {
                double b = popNum();
                double a = popNum();
                char op = popOp();
                pushNum(applyOp(a, b, op));
            }
            popOp();
        }

        else
        {
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(exp[i]))
            {
                double b = popNum();
                double a = popNum();
                char op = popOp();
                pushNum(applyOp(a, b, op));
            }
            pushOp(exp[i]);
        }

        i++;
    }

    while (opTop != -1)
    {
        double b = popNum();
        double a = popNum();
        char op = popOp();
        pushNum(applyOp(a, b, op));
    }

    return popNum();
}

int main()
{
    char expression[MAX];

    while (1)
    {
        showUI();
        setColor(11);
        printf("\nEnter expression: ");

        setColor(15);
        scanf(" %[^\n]", expression);

        if (strcmp(expression, "exit") == 0)
        {
            setColor(12);
            printf("\nExiting Calculator... 👋\n");
            break;
        }

        numTop = -1;
        opTop = -1;

        double result = evaluate(expression);

        setColor(10); // Green
        printf("\nResult = %.2lf\n", result);

        setColor(8);
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}