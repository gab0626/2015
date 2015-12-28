//class sample
//{
//    public static void Main()
//    {
//        System.Console.WriteLine("Hello, World!");
//    }
//}

//class text01
//{
//    public static void Main()
//    {
//        int a = 10, b = 10, total;

//        total = a + b;

//        System.Console.WriteLine(a + " + " + b + " = " + total);
//    }
//}

//class text02
//{
//    public static void Main()
//    {
//        int a = 10, b = 10;

//        System.Console.WriteLine(a + " + " + b + " = " + (a + b));
//    }
//}

//class text03
//{
//    public static void Main()
//    {
//        System.Console.Write("a");
//        System.Console.Write("b");
//        System.Console.Write("c");
//        System.Console.WriteLine();
//    }   
//}

//class text04
//{
//    public static void Main()
//    {
//        int x = 10;
//        System.Console.WriteLine("x = {0}", x);
//        System.Console.WriteLine("x = {0}, xの10倍は{1}です", x, x * 10);
//        System.Console.WriteLine("{0}は{1}ですが、{2}は{1}ではありません", "猫", "ほ乳類", "トカゲ");
//    }
//}

//class text05
//{
//    public static void Main()
//    {
//        int x = 10, y = 123456789;

//        System.Console.WriteLine("123456789012345678901234567890");
//        System.Console.WriteLine("{0,10}", "abc");
//        System.Console.WriteLine("{0,5}", "def");
//        System.Console.WriteLine("{0,0}", "ghi");
//        System.Console.WriteLine("{0,10}{1,10}", "あ", "い");
//        System.Console.WriteLine("{0,-10}{1,-10", "あ", "い");
//        System.Console.WriteLine("x = {0,5},y = {1,3}", x, y);
//    }
//}

//class text07
//{
//    public static void Main()
//    {
//        System.Console.WriteLine("D{0,10:D}", 123);
//        System.Console.WriteLine("X{0,10:X}", 123);
//        System.Console.WriteLine("E{0,10:E}", 123);
//        System.Console.WriteLine("F{0,10:F}", 123.456);
//        System.Console.WriteLine("F{0,10:F5}", 123.456);
//        System.Console.WriteLine("C{0,10:C}", 123456);
//        System.Console.WriteLine("N{0,10:N}", 1234.4568);
//        System.Console.WriteLine("P{0,10:P}", 0.05);
//        System.Console.WriteLine("G{0,10:G}", 123.456);
//    }
//}

//class readline01                  ユーザーが入力した情報を取得して表示
//{
//    public static void Main()
//    {
//        string name;
//        System.Console.Write("あなたのお名前は___");
//        name = System.Console.ReadLine();
//        System.Console.WriteLine("あなたのお名前は{0}さんですね？", name);
//    }
//}

//class Training01                  自分の回答
//{
//    public static void Main()
//    {
//        string Name;
//        Name = System.Console.ReadLine();
//        System.Console.WriteLine("あなたのお名前は{0}です", Name);
//    }
//}

class TrainingAnswer01
{
    public static void Main()
    {
        string str = System.Console.ReadLine();
        System.Console.WriteLine(str);
    }
}