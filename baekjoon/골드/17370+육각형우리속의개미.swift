//
//  main.swift
//  algostudy
//
//  Created by 강희선 on 2021/09/14.
//
import Foundation
let n = Int(readLine()!)!
var answer = 0
let dx = [1, 1, 1, -1, -1, -1]
let dy = [-1, 1, 0, 0, -1, 1]
let direction = [[2,4], [2,5], [0,1], [4,5], [0,3], [1,3]]
var visit = Array(repeating: [Bool](repeating: false, count: 200), count: 200)
func dfs(_ cnt: Int, _ dir: Int, _ x: Int, _ y: Int){
    if visit[x][y]{
        if(cnt == n){
            answer += 1
        }
        return
    }
    if cnt == n{
        return
    }
    visit[x][y] = true
    dfs(cnt+1, direction[dir][0], x+dx[direction[dir][0]], y+dy[direction[dir][0]])
    dfs(cnt+1, direction[dir][1], x+dx[direction[dir][1]], y+dy[direction[dir][1]])
    visit[x][y] = false
}

visit[100][100] = true
dfs(0, 3, 99,100)
print(answer)
