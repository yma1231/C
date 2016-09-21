#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
	char value;
	struct node *next;
};
struct node *create(int value);
int insert(struct node *new, struct node *root);
int printLinkList(const char *str, struct node *root);
struct node *removeDuplicated(struct node *root);

int main(int argc, const char *argv[]) {
	struct node *root = create(0); // create a HEAD with value as 0
	int i, len = 0, retval;
	if (argv[1]) {
		len = strlen(argv[1]);
	} else
		return -1;
	struct node *tail = root;
	for (i = 0; i < len; i++) {
		struct node *new = create(argv[1][i]);
		retval = insert(new, tail);
		tail = new;
	}
	printLinkList("Link List: ", root);
	root = removeDuplicated(root);
	printLinkList("After removed duplicated chars: ", root);
	free(root);
	return printf("result: %d\n", retval);
}

int printLinkList(const char *str, struct node *root) {
	if (root == NULL) {
		printf("Link List is empty!\n");
		return -1;
	}
	struct node *ll = root;

	while (ll != NULL) {
		printf("%s: %c\n", str, ll->value);
		ll = ll->next;
	}
	return 0;
}

struct node *create(int value) {
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->value = value;
	new->next = NULL;
	return new;
}

int insert(struct node *new, struct node *root) {
	if (root->next == NULL)
		root->next = new;
	else
		return -1;
	return 0;
}

struct node *removeDuplicated(struct node *root) {
	struct node *ll = root;
	char arr[256] = "\0";

	if (root == NULL) {
		return root;
	}
	while (ll->next != NULL) {
		if (arr[ll->next->value] == 1) {
			ll->next = ll->next->next;
		} else {
			arr[ll->next->value] = 1;
			ll = ll->next;
		}
	}
	return root;
}

