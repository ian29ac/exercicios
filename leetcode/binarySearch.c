int search(int* nums, int numsSize, int target) {
    int esq = 0, dir = numsSize-1; // inicializando os índices de início e fim da busca binária

    while (esq<=dir) { // loopa enquanto ainda houver elementos no intervalo de busca
        int meio = esq + (dir-esq)/2; // o meio é a média entre os limites, calculada de modo a evitar overflow

        if (nums[meio] == target) return meio; // se encontrar, retorna
        if (nums[meio] < target) {
            esq = meio+1; // se o alvo for maior, desloca o limite inferior para frente e parte pro próximo loop
            continue;
        }
        dir = meio-1; // se o alvo for menor, desloca o limitee superior para trás de parte pro próximo loop
    }
    return -1; // se não encontrar, retorna -1
}