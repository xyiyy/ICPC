#define MAXN 100010
char str[MAXN], s[MAXN];
//MAXN����Ҫ����ԭ�ַ���������
int p[MAXN];
//p�е����ֵ-1����������Ӵ��ĳ���
int n;

void Manacher() {
    n = strlen(s);
    str[0] = '$';
    str[1] = '#';
    for (int i = 0; i < n; i++)str[2 * i + 2] = s[i], str[2 * i + 3] = '#';
    n = n * 2 + 2;
    str[n] = 0;
    int mx = 0, id;
    for (int i = 1; i < n; i++) {
        if (mx > i)p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        for (; str[i + p[i]] == str[i - p[i]]; p[i]++);
        if (p[i] + i > mx)mx = p[i] + i, id = i;
    }
}
