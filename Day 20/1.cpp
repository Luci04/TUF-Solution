#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right, *nextRight;
};

void connect(struct Node *root)
{
    queue<Node *> q;
    q.push(root);

    q.push(NULL);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        if (p != NULL)
        {

            p->nextRight = q.front();

            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }

        else if (!q.empty())
            q.push(NULL);
    }
}

struct Node *newnode(int data)
{
    struct Node *node = (struct Node *)
        malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = node->nextRight = NULL;
    return (node);
}

int main()
{

    /*		10 
			/ \ 
		   8  2 
		  /	   \ 
 	     3 	   90 
	*/
    struct Node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->right->right = newnode(90);

    connect(root);

    printf("Following are populated nextRight pointers in \n"
           "the tree (-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
           root->nextRight ? root->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->data,
           root->left->nextRight ? root->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->data,
           root->right->nextRight ? root->right->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
           root->left->left->nextRight ? root->left->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
           root->right->right->nextRight ? root->right->right->nextRight->data : -1);
    return 0;
}
