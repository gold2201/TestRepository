using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Бронирование_мест_в_самолёте
{
    class Program
    {
        static void Main(string[] args)
        {
            //#3Регестрация пассажиров на рейс самолета

            int[] sectors = { 10, 15, 20, 25, 35 };
            bool isOpen = true;
            int booking;
            int numberOfSeats;
            int check = 0;
            int cash = 0;

            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("Введите баланс на свой карточке (USD): ");
            cash = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(" ");


            while (true)
            {
                Console.SetCursorPosition(0, 25);
                Console.ForegroundColor = ConsoleColor.Blue;

                for (int i3 = 0; i3 < sectors.Length; i3++)
                {
                    Console.WriteLine($"В секторе {i3 + 1} свободно {sectors[i3]} ");
                }
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("\n \nЦены за место в секторах:\n \nСектор 1 - 35 USD\nCектор 2 - 30 USD\nСектор 3 - 25 USD\nСектор 4 - 20 USD\nСектор 5 - 10 USD\n");

                Console.ForegroundColor = ConsoleColor.Blue;
                Console.SetCursorPosition(0, 0);
                Console.WriteLine("Регестрация рейса.");
                Console.WriteLine("\n1 - забронировать место\n2 - выход из программы\n");
                Console.Write("Введите номер команды: ");


                switch (Convert.ToInt32(Console.ReadLine()))
                {
                    case 1:
                        Console.WriteLine("В каком секторе вы хотите забронировать место?");
                        booking = Convert.ToInt32(Console.ReadLine());

                        if (booking < 1 || booking > 5)
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("Такого сектора не существует!");
                            break;
                        }

                        Console.WriteLine("Сколько мест вы хотите забронировать?");
                        numberOfSeats = Convert.ToInt32(Console.ReadLine());

                        switch (booking)
                        {
                            case 1:
                                check = sectors[0] - numberOfSeats;

                                cash -= 35 * numberOfSeats;

                                if (check >= 0 && cash > 0)
                                {
                                    Console.Clear();
                                    sectors[0] -= numberOfSeats;
                                    Console.ForegroundColor = ConsoleColor.Green;
                                    Console.WriteLine($"Было успешно забронированно {numberOfSeats} мест!\nНа вашем балансе осталось {cash} USD \n \nДля продолжения нажмите ENTER");

                                }

                                else if (cash <= 0)
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("На вашем балансе недостаточно средств. Бронирование отклонено.");
                                    break;

                                }

                                else
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("В данном секторе нет столько мест. Бронирование отклонено.");
                                    break;
                                }

                                break;

                            case 2:

                                check = sectors[1] - numberOfSeats;

                                cash -= 30 * numberOfSeats;

                                if (check >= 0 && cash > 0)
                                {
                                    Console.Clear();
                                    sectors[1] -= numberOfSeats;
                                    Console.ForegroundColor = ConsoleColor.Green;
                                    Console.WriteLine($"Было успешно забронированно {numberOfSeats} мест!\nНа вашем балансе осталось {cash} USD \n \nДля продолжения нажмите ENTER");
                                }

                                else if (cash <= 0)
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("На вашем балансе недостаточно средств. Бронирование отклонено.");
                                    break;

                                }

                                else
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("В данном секторе нет столько мест. Бронирование отклонено.");
                                    break;
                                }

                                break;

                            case 3:
                                check = sectors[2] - numberOfSeats;

                                cash -= 25 * numberOfSeats;

                                if (check >= 0 && cash > 0)
                                {
                                    Console.Clear();
                                    sectors[2] -= numberOfSeats;
                                    Console.ForegroundColor = ConsoleColor.Green;
                                    Console.WriteLine($"Было успешно забронированно {numberOfSeats} мест!\nНа вашем балансе осталось {cash} USD \n \nДля продолжения нажмите ENTER");
                                }

                                else if (cash <= 0)
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("На вашем балансе недостаточно средств. Бронирование отклонено.");
                                    break;

                                }

                                else
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("В данном секторе нет столько мест. Бронирование отклонено.");
                                    break;
                                }

                                break;

                            case 4:
                                check = sectors[3] - numberOfSeats;

                                cash -= 20 * numberOfSeats;

                                if (check >= 0 && cash > 0)
                                {
                                    Console.Clear();
                                    sectors[3] -= numberOfSeats;
                                    Console.ForegroundColor = ConsoleColor.Green;
                                    Console.WriteLine($"Было успешно забронированно {numberOfSeats} мест!\nНа вашем балансе осталось {cash} USD \n \nДля продолжения нажмите ENTER");
                                }

                                else if (cash <= 0)
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("На вашем балансе недостаточно средств. Бронирование отклонено.");
                                    break;

                                }

                                else
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("В данном секторе нет столько мест. Бронирование отклонено.");
                                    break;
                                }

                                break;

                            case 5:
                                check = sectors[4] - numberOfSeats;

                                cash -= 10 * numberOfSeats;

                                if (check >= 0 && cash > 0)
                                {
                                    Console.Clear();
                                    sectors[4] -= numberOfSeats;
                                    Console.ForegroundColor = ConsoleColor.Green;
                                    Console.WriteLine($"Было успешно забронированно {numberOfSeats} мест!\nНа вашем балансе осталось {cash} USD \n \nДля продолжения нажмите ENTER");
                                }

                                else if (cash <= 0)
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("На вашем балансе недостаточно средств. Бронирование отклонено.");
                                    break;

                                }

                                else
                                {
                                    Console.Clear();
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    Console.WriteLine("В данном секторе нет столько мест. Бронирование отклонено.");
                                    break;
                                }

                                break;
                        }
                        break;

                    case 2:
                        Console.ForegroundColor = ConsoleColor.Yellow;
                        Console.WriteLine("Программа завершена!");
                        Console.ReadKey();
                        Environment.Exit(0);
                        break;

                }

                Console.ReadKey();
                Console.Clear();

            }

        }
    }
}
