int dep_flag[N]={0};

void printTree(int lv, int node)
{
    int i, j;
    int indent = 0;
    int buff   = -1;
    int preLF  = 0;

    if (lv == 1) printf("   %c", node);

    for (i = 0; i <= N; i++)
        if (i == N || parent[i] == node) {
            if (buff != -1)  {
                if (i == N) dep_flag[lv] = 0;
                else        dep_flag[lv] = 1;
                if (indent) {
                    for (j = 0; j < lv; j++)
                        if (dep_flag[j]) printf(" |  ");
                        else             printf("    ");
                    printf(" |-%c", V[buff]);
                } else {
                    printf("---%c", V[buff]);
                    indent = 1;
                }
                printTree(lv+1, buff);
                preLF = 1;
            }
            buff = i;
        }
    if (!preLF) printf("\n");
}
