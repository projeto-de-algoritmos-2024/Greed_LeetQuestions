class Solution{
   public:
    long long maxSpending(vector<vector<int>>& values) {
        //pegando lojas 
        int lojas = values.size();   
        //itens por lojas     
        int itens = values[0].size();    

        //armazenado em um unico vetor todos os itens 
        vector<int> combina;
        for (int i = 0; i < lojas; i++) {
            for (int j = 0; j < itens; j++) {
                combina.push_back(values[i][j]);
            }
        }

        // Ordenando em ordem crescente
        sort(combina.begin(), combina.end());

        //calculando 
        long long resultado = 0;
        int totalItens = itens * lojas;

        for (int i = 1; i <= totalItens; i++) {
            resultado += static_cast<long long>(i) * combina[i - 1];
        }

        return resultado;
    }
};
