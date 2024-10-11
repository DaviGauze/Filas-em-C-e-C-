using System;

class ClasseFila
{
    private int[] fila;
    private int ini;
    private int fim;

    public ClasseFila(int i, int f)
    { 
        fila = new int[5];
        ini = i;
        fim = f;
    }

    public bool FilaVazia()
    {
        return ini == -1 && fim == -1;
    }

    public bool FilaCheia()
    {
        return (fim + 1 == ini) || (fim == 4 && ini == 0);
    }

    public void Enqueue(int valor)
    {
        if (FilaCheia())
        {
            Console.WriteLine("FILA CHEIA");
            return;
        }

        if (FilaVazia())
        {
            ini = 0;
            fim = 0;
        }
        else if (fim == fila.Length - 1 && ini > 0)
        {
            fim = 0;
        }
        else
        {
            fim += 1;
        }

        fila[fim] = valor;
        Console.WriteLine($"Valor {valor} inserido na fila.");
    }

    public int Dequeue()
    {
        if (FilaVazia())
        {
            Console.WriteLine("FILA VAZIA");
            return -1;
        }

        int valor = fila[ini];

        if (ini == fim)
        {
            ini = -1;
            fim = -1;
        }
        else if (ini == fila.Length - 1)
        {
            ini = 0;
        }
        else
        {
            ini += 1;
        }

        Console.WriteLine($"Valor {valor} removido da fila.");
        return valor;
    }

    public void MostrarFila()
    {
        if (FilaVazia())
        {
            Console.WriteLine("FILA VAZIA");
            return;
        }

        int i = ini;
        Console.Write("Fila: ");
        while (true)
        {
            Console.Write(fila[i] + " ");
            if (i == fim)
            {
                break;
            }
            i = (i + 1) % fila.Length;
        }
        Console.WriteLine();
    }
}

class ClasseFila
{
    static void Main(string[] args)
    {
        int OP, valor;
        ClasseFila filaObj = new ClasseFila(-1, -1);

        while (true)
        {
            Console.Clear();
            Console.WriteLine("1 - Inserir na Fila.");
            Console.WriteLine("2 - Retirar da Fila.");
            Console.WriteLine("3 - Mostrar Fila.");
            Console.WriteLine("0 - Sair.");
            Console.Write("Entre com a opcao: ");
            OP = int.Parse(Console.ReadLine()); 

            if (OP == 0)
            {
                break;
            }
            else if (OP == 1)
            {
                Console.Write("Entre com o valor a ser inserido: ");
                valor = int.Parse(Console.ReadLine());
                filaObj.Enqueue(valor);
            }
            else if (OP == 2)
            {
                filaObj.Dequeue();
            }
            else if (OP == 3)
            {
                filaObj.MostrarFila();
            }

            Console.WriteLine("Pressione qualquer tecla para continuar...");
            Console.ReadKey();
        }
    }
}
