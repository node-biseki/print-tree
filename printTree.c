int preLF=0;
int dep_flag[N]={0};

void printTree(int lv, int node)
{
    int i, j;
    int indent = 0;
    int buff   = -1;

    for (i = 0; i < N; i++)
        if (parent[i] == node || i == N-1) {
            if (buff != -1)  {
                if (i == N-1) dep_flag[lv] = 0;
                else          dep_flag[lv] = 1;
                if (indent) {
                    for (j = 0; j < lv; j++)
                        if (dep_flag[j]) printf("|   ");
                        else             printf("    ");
                    printf(" |-%c", V[buff]);
                } else {
                    printf("---%c", V[buff]);
                    indent = 1;
                }
                preLF = 0;
                printTree(lv+1, buff);
                preLF = 1;
            }
            //最後はN-1が入るがそのbuffは無視される
            buff = i;
        }
    if (!preLF) printf("\n");
}
