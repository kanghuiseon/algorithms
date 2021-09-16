//
//  main.swift
//  algostudy
//
//  Created by 강희선 on 2021/09/14.
//
import Foundation


let nmk = readLine()!.split(separator: " ").map{ Int(String($0))! }
let n = nmk[0]
let m = nmk[1]
let kk = nmk[2]
var arr = Array(repeating: [Int](repeating: 0, count: m), count: n)
for i in 0..<n{
    let tmp = readLine()!.split(separator: " ").map{ Int(String($0))! }
    for j in 0..<m{
        arr[i][j] = tmp[j]
    }
}
var tmp = arr

func rotate(_ r: Int){
    let x = r
    let y = r
    //왼
    for i in x+1..<n-r{
        tmp[i][y] = arr[i-1][y]
    }
    //아래
    for i in y+1..<m-r{
        tmp[n-r-1][i] = arr[n-r-1][i-1]
    }
    //오
    for i in x+1..<n-r{
        tmp[n-1-i][m-r-1] = arr[n-1-i+1][m-r-1]
    }
    //위
    for i in y+1..<m-r{
        tmp[x][i-1] = arr[x][i]
    }
}
//let rotateSize =
for i in 0..<min(n,m)/2{
    let rotateSize = kk%(2*(n-2*i + m-2*i)-4)
    for _ in 0..<rotateSize{
        rotate(i)
        arr = tmp
    }
}
var answer = ""
arr.forEach {
    $0.forEach{
        answer += "\($0) "
    }
    answer += "\n"
}
answer.removeLast()
print(answer)
