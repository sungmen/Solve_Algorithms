func solution(arr1 [][]int, arr2 [][]int) [][]int {
    arr3 := make([][]int, len(arr1))
    for i := range arr3 {
        arr3[i] = make([]int, len(arr2[0]))
    }
    
    for i := 0; i < len(arr1); i++ {
        for j := 0; j < len(arr2[0]); j++ {
            for l := 0; l < len(arr1[0]); l++ {
                arr3[i][j] += arr1[i][l] * arr2[l][j]
            }
        }
    }
    
    return arr3
}