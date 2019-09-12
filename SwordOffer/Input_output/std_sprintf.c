// sprintf 的用法:将各种格式的数转化为字符串
void std_sprintf() {
    //(1)将大数转化为字符串进行求值
    int value = 52112;
    char array[10];     //类型是字符串；当时写成了int
    sprintf(array, "%d", value);
    printf("string_value is %s\n", array);

    // (2)将两个大数进行连接,并将其转化为整数
    int num1 = 1234;
    int num2 = 5678;
    char number[10];
    sprintf(number, "%d%d", num1, num2);
    printf("string_number is %s\n", number);

    int num = atol(number);     // 只能转化整数
    printf("number_num is %d\n", num);

    //(3) 两个整数转化为大夫点的小数
    char number_float[10];
    sprintf(number_float, "%d%c%d", 12, '.', 234);
    printf("float_string is %s\n", number_float);

    //(4) 浮点类型数转化为字符串
    char number_float_two[10];
    sprintf(number_float_two, "%4.2f", 1234.2564);       // 还能进行四舍五入
    printf("number_float_two_string is %s\n", number_float_two);

    //(5) 还可以在后面加单位
    char cm[10];
    sprintf(cm, "%4.2f%s", 1234.2564, "cm");       // 还能进行四舍五入
    printf("cm_string is %s\n", cm);

    //(6)将两个字符串连接在一起
    char a1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char a2[] = {'H', 'I', 'J', 'K', 'L', 'M', 'N'};
    char s[20];
//    sprintf(s, "%s%s", a1, a2); //Don't do that!
    //十有八九要出问题了。是否可以改成：
//    sprintf(s, "%7s%7s", a1, a2);
    //也没好到哪儿去，正确的应该是：
    sprintf(s, "%.7s%.7s", a1, a2);//产生："ABCDEFGHIJKLMN"
    printf("s_strcat_string: is %s\n", s);

}
