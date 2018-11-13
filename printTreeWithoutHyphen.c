void printTreeWithoutHyphen(int lv, int node)
{
    int i, j;
    int indent = 0;
    int preLF  = 0;

    if (lv == 1) printf(" %c", V[node]);

    for (i = 0; i < N; i++) {
        if (parent[i] == node) {
            if (indent) {
                for (j = 0; j < lv; j++) printf("  ");
            } else {
                indent = 1;
            }
            printf(" %c", V[i]);
            printTreeWithoutHyphen(lv+1, i);
            preLF = 1;
        }
    }
    if (!preLF) printf("\n");
}
