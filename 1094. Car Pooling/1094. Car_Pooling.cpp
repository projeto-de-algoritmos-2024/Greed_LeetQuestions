class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengerChange(1001, 0); // Limite de localização

        // Registrar mudanças no número de passageiros
        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            passengerChange[from] += numPassengers; // Registro dos passageiros que embarcam
            passengerChange[to] -= numPassengers;  // Registro dos passageiros que desembarcam
        }

        // Simular o trajeto e verificar a capacidade
        int currentPassengers = 0;
        for (int i = 0; i <= 1000; ++i) {
            currentPassengers += passengerChange[i];
            if (currentPassengers > capacity) {
                return false; // Capacidade excedida
            }
        }

        return true;
    }
};