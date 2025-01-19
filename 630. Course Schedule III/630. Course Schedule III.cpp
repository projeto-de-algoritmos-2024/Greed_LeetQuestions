class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Ordenar os cursos pelo último dia (lastDay) em ordem crescente
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap; // Heap para armazenar a duração dos cursos
        int totalTime = 0;          // Tempo total utilizado até agora

        for (const auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            // Adicionar a duração do curso ao tempo total
            maxHeap.push(duration);
            totalTime += duration;

            // Se o tempo total exceder o último dia permitido, remover o curso mais longo
            if (totalTime > lastDay) {
                totalTime -= maxHeap.top(); // Subtrair a maior duração
                maxHeap.pop();
            }
        }

        // O tamanho da heap é o número máximo de cursos que podem ser realizados
        return maxHeap.size();
    }
};