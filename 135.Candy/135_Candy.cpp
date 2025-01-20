class Solution {
public:
    int candy(vector<int>& ratings) {
        int criancas = ratings.size(); //obtendo o numero de crianças 
        vector<int> doces(criancas, 1); // distribui um doce para cada crianca

       
        for (int i = 1; i < criancas; ++i) { //pecorre da primeira até a penultima 
            if (ratings[i] > ratings[i - 1]) {
                //se uma criança tiver uma classificaçao maior q a anterior, ela recebe mais um doce
                doces[i] = doces[i - 1] + 1;
            }
        }

       
        for (int i = criancas - 2; i >= 0; --i) {// pecorre no sentido contrario
            if (ratings[i] > ratings[i + 1]) {
                //Garante que se uma criança tem uma classificação maior que o vizinho da direita, ela terá mais doces que ele.
                doces[i] = max(doces[i], doces[i + 1] + 1); 
            }
        }

      
        return accumulate(doces.begin(), doces.end(), 0);
    }
};

    
