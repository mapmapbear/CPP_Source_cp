#include <stdio.h>
#include <stdlib.h>

/*类型定义*/
#define datatype char
typedef struct Node
{
  datatype data;
  struct Node *lChild, *rChild;
} BiTreeNode; //二叉树结点

/*函数说明*/
BiTreeNode *createBiTree();       /*建立一个二叉树，返回二叉树的根结点*/
void preOrder(BiTreeNode *root);  /*先序遍历二叉树，root是二叉树的根结点*/
void inOrder(BiTreeNode *root);   /*中序遍历二叉树，root是二叉树的根结点*/
void postOrder(BiTreeNode *root); /*后序遍历二叉树，root是二叉树的根结点*/
int numOfLeaf(BiTreeNode *root);/*求叶子结点数*/
int numOfOneChild(BiTreeNode *root);/*求度为1的结点数*/
int numOfTwoChild(BiTreeNode *root);/*求度为2的结点数*/

int main(int argc, char const *argv[])
{
  BiTreeNode *root;
  root = createBiTree();
  printf("前序遍历二叉树：");
  preOrder(root);
  printf("\n中序遍历二叉树：");
  inOrder(root);
  printf("\n中序遍历二叉树：");
  postOrder(root);
  printf("\n");
  
  numOfLeaf(root);

  return 0;
}
/*建立一个二叉树*/
BiTreeNode *createBiTree()
{
  BiTreeNode *q;     //临时生成的新结点
  BiTreeNode *s[100]; //指针数组，存放二叉树中的所有结点，最多只能有100个结点
  int j, i;
  datatype x; //结点的数据域的值
  printf("建立二叉树，输入结点对应的编号和值，编号和值之间用逗号隔开，编号从1开始，值以'$'为结束\n");
  printf("编号,字母=");
  scanf("%d,%c", &i, &x);
  while (i != 0 && x != '$')
  {
    q = (BiTreeNode *)malloc(sizeof(BiTreeNode)); /*建立新结点*/
    q->data = x;                                  /*x放入数据域*/
    q->lChild = NULL;
    q->rChild = NULL; /*左右孩子都为空*/
    s[i] = q;         /*q结点地址存入s指针数组中*/
    if (i != 1)
    {            /*i=1，对应的结点是根结点*/
      j = i / 2; /*求双亲结点的编号j*/
      if (i % 2 == 0)
      {
        s[j]->lChild = q; /*q结点编号为偶数则挂在双亲结点j的左边*/
      }
      else
      {
        s[j]->rChild = q; /*q结点编号为偶数则挂在双亲结点j的右边*/
      }
    }
    printf("编号,字母=");
    scanf("%d,%c", &i, &x);
  }
  return s[1]; //返回根结点地址
}
/*先序遍历二叉树，递归实现*/
void preOrder(BiTreeNode *root)
{
  if(root != NULL){
    printf("%c ",root->data);
    preOrder(root->lChild);
    preOrder(root->rChild);
  }
}
/*中序遍历二叉树，递归实现*/
void inOrder(BiTreeNode *root)
{
  if(root != NULL){
    preOrder(root->lChild);
    printf("%c ",root->data);
    preOrder(root->rChild);
  }
}
/*后序遍历二叉树，递归实现*/
void postOrder(BiTreeNode *root)
{
  if(root != NULL){
    preOrder(root->lChild);
    preOrder(root->rChild);
    printf("%c ",root->data);
  }
}
/*求叶子结点数*/
int numOfLeaf(BiTreeNode *root){
  int count = 0;
  if(root == NULL)
    return 0;
  if(root->lChild != NULL)
    count++;
  if(root->rChild != NULL)
    count++;
  count = numOfLeaf(root->lChild)+numOfLeaf(root->rChild)+count;
  printf("the %c value is:%d\n",root->data,count);
  return count;
}
/*求度为1的结点数*/
int numOfOneChild(BiTreeNode *root){
  int count = 0;
  int sum = 0;
  if(root->lChild != NULL)
    ++count;
  if(root->rChild != NULL)
    ++count;
  if(count == 1)
    sum++;
  printf("Thre Tree Node %c count:%d\n",root->data,count);
  if(root->lChild != NULL)
    numOfLeaf(root->lChild);
  if(root->rChild != NULL)
    numOfLeaf(root->rChild);
  return count;
  return sum;
}
/*求度为2的结点数*/
int numOfTwoChild(BiTreeNode *root){
  int count = 0;
  int sum = 0;
  if(root->lChild != NULL)
    ++count;
  if(root->rChild != NULL)
    ++count;
  if(count == 2)
    sum++;
  printf("Thre Tree Node %c count:%d\n",root->data,count);
  if(root->lChild != NULL)
    numOfLeaf(root->lChild);
  if(root->rChild != NULL)
    numOfLeaf(root->rChild);
  return count;
  return sum;
}


