class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Em geral, podemos resolver qualquer coisa primeiro rotacionando e depois invertendo uma única vez.

        // O ponto principal é:
        // É mais fácil mover o zero para a esquerda, ou inverter ele para ele se aproximar da primeira posição?

        int n = nums.size();
        int zero_position = 0;

        // Procura o zero para tomarmos a decisão
        // Sim, isso é bem guloso.
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
                zero_position = i;
                break;
            }
        }

        int counter = 40028922; // Dificilmente teremos um número maior que isso e eu to com preguiça de procurar a definição do maior inteiro.

        // Agora, vamos primeiro fazer as inversões até o zero.
        // Se o coiso estiver além da metade, iremos apenas contabilizar as inversões a direita.

        int rotationsCounter = 0;
        bool sucessful = true;

        for (int i= 0; i < n; i++){
            int curPointer = (zero_position + i) % n;

            if (nums[curPointer] != rotationsCounter){
                sucessful = false;
                break;
            }
            rotationsCounter++;
        }

        if (sucessful) {
            counter = zero_position;
            counter = min(counter, n - zero_position+2);
        }
        int inversionsCounter = 0;
        sucessful = true;

        for (int i= 0; i < n; i++){
            int curPointer = (zero_position - i + n) % n;

            if (nums[curPointer] != inversionsCounter){
                sucessful = false;
                break;
            }
            inversionsCounter++;
        }

        if (sucessful){
            counter = min(counter, n - zero_position); 
            counter = min(counter, 2 + zero_position); 
        }

        return (counter == 40028922 ? -1 : counter);
    }
};
