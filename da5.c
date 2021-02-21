//Binary Search Tree
#include <stdio.h>
  #include <stdlib.h>

  struct treeNode {
        int data;
        struct treeNode *left, *right;
  };

  struct treeNode *root = NULL;

  struct treeNode* createNode(int data) {
        struct treeNode *newNode;
        newNode = (struct treeNode *) malloc(sizeof (struct treeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return(newNode);
  }

  void insertion(struct treeNode **node, int data) {
        if (*node == NULL) {
                *node = createNode(data);
        } else if (data < (*node)->data) {
                insertion(&(*node)->left, data);
        } else if (data > (*node)->data) {
                insertion(&(*node)->right, data);
        }
  }


  void deletion(struct treeNode **node, struct treeNode **parent, int data) {
        struct treeNode *tmpNode, *tmpParent;
        if (*node == NULL)
                return;
        if ((*node)->data == data) {
                if (!(*node)->left && !(*node)->right) {
                        if (parent) {
                                if ((*parent)->left == *node)
                                        (*parent)->left = NULL;
                                else
                                        (*parent)->right = NULL;
                                free(*node);
                        } else {
                                free(*node);
                        }
                } else if (!(*node)->right && (*node)->left) {
                        tmpNode = *node;
                        (*parent)->right = (*node)->left;
                        free(tmpNode);
                        *node = (*parent)->right;
                } else if ((*node)->right && !(*node)->left) {
                        tmpNode = *node;
                        (*parent)->left = (*node)->right;
                        free(tmpNode);
                        (*node) = (*parent)->left;
                } else if (!(*node)->right->left) {

                        tmpNode = *node;

                        (*node)->right->left = (*node)->left;

                        (*parent)->left = (*node)->right;
                        free(tmpNode);
                        *node = (*parent)->left;
                } else {
                        tmpNode = (*node)->right;
                        while (tmpNode->left) {
                                tmpParent = tmpNode;
                                tmpNode = tmpNode->left;
                        }
                        tmpParent->left = tmpNode->right;
                        tmpNode->left = (*node)->left;
                        tmpNode->right =(*node)->right;
                        free(*node);
                        *node = tmpNode;
                }
        } else if (data < (*node)->data) {
                deletion(&(*node)->left, node, data);
        } else if (data > (*node)->data) {
                deletion(&(*node)->right, node, data);
        }
  }
  
  void find(struct treeNode *node, int data) {
      
        if (!node)
                return;
        else if (data < node->data) {
                find(node->left, data);
        } else if (data > node->data) {
                find(node->right, data);
        } else
                printf("data found: %d\n", node->data);
        return;

  }

  void traverse(struct treeNode *node) {
        if (node != NULL) {
                traverse(node->left);
                printf("%3d", node->data);
                traverse(node->right);
        }
        return;
  }

  int main() {
        int data, ch;
        printf("1. Insertion\n2. Deletion\n3. Search Element \n4. Inorder traversal\n5. Exit\n");
        while (1) {
                
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1: 
                                printf("Enter your data:");
                                scanf("%d", &data);
                                insertion(&root, data);
                                break;
                        case 2:
                                printf("Enter your data:");
                                scanf("%d", &data);
                                deletion(&root, NULL, data);
                                break;
                        case 3:
                                printf("Enter value for data:");
                                scanf("%d", &data);
                                find(root, data);
                                break;
                        case 4:
                                printf("Inorder Traversal:\n");
                                traverse(root);
                                printf("\n");
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("You have entered wrong option\n");
                                break;
                }
        }
        return 0;

  }
