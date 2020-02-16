#include <stdio.h>

/*test recursion write in 2020/1/6*/
int *findJump1(int *);
int *findJump2(int *);

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9};
    int *ans1, *ans2;
    ans1 = findJump1(arr);
    // ans2 = findJump2(arr);
    printf("the arr jumped at %d(1)", *ans1);

    return 0;
}

int *findJump1(int *A)
{
    //question like this requires first push in to stack,
    //and then pop the stack to get reversed, as the check must be done in reverse.
    //the ans is not at the top of stack, but in the middle of stack
    //so the question is to return a frame which lies in middle of stack.

    if (*A == 9)
        return A; // what does this line do?
    //it may just return to the 2nd stackframe.
    else
        findJump1(A + 1); // push

    static int *target; // this line must be static , as it will re-init at every call.

    if (*A == 5)
    { //here I am attemping to "save" the middle frame value;
        target = A;
    }

    return target;
}

// int *findJump1(int *A)
// {
//     //question like this requires first push in to stack,
//     //and then pop the stack to get reversed, as the check must be done in reverse.
//     //the ans is not at the top of stack, but in the middle of stack
//     //so the question is to return a frame which lies in middle of stack.

//     if (*A == 9)
//     {
//         int *target = NULL;
//         return A; // what does this line do?
//     }
//     //it may just return to the 2nd stackframe.
//     else
//         int *target = findJump1(A + 1); // push
//     if (*A == 5)
//     {               //here I am attemping to "save" the middle frame value;
//         target = A; // this will be undecleared, as
//     }

//     return target;
// }
