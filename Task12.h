void decrease(void);
void decreasing_Number(void);
void union_Free(void);

union Byte
{
    struct {
        unsigned a0 : 3;
        unsigned a1 : 29;
    }bytes;

    int num;
};

void decrease(int num)
{
    union Byte x;

    x.num = num;

    printf("%d", x.bytes.a1);
    _getch();
}





















































//void union_Free()
//{
//    union Byte x;
//
//    x.bytes.a0 = 0;
//    x.bytes.a1 = 0;
//    x.bytes.a2 = 0;
//    x.bytes.a3 = 0;
//    x.bytes.a4 = 0;
//    x.bytes.a5 = 0;
//    x.bytes.a6 = 0;
//    x.bytes.a7 = 0;
//    x.bytes.a8 = 0;
//    x.bytes.a9 = 0;
//}