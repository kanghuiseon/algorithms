//
//  main.swift
//  algostudy
//
//  Created by 강희선 on 2021/09/14.
//
import Foundation

func sortAcc(_ a: [Int], _ b: [Int]) -> Bool{
    if a[0] == b[0]{
        if(a[1] == b[1]){
            return a[2] < b[2]
        }else{
            return a[1] < b[1]
        }
    }else{
        return a[0] < b[0]
    }
}
func impossible(_ result: Set<[Int]>) -> Bool{
    for i in result{
        let x = i[0]
        let y = i[1]
        let build = i[2]
        // 기둥
        if build == 0{
            if y == 0 || result.contains([x, y-1, 0]) || result.contains([x, y, 1]) || result.contains([x-1, y, 1]){
                continue
            }else{
                return false
            }
        }else{ // 보
            if result.contains([x, y-1, 0]) || result.contains([x+1, y-1, 0]) || (result.contains([x-1, y, 1]) && result.contains([x+1, y, 1])) {
                continue
            }else{
                return false
            }
        }
    }
    return true
}
func solution(_ n:Int, _ build_frame:[[Int]]) -> [[Int]] {
    var result: [[Int]] = []
    var answer = Set<[Int]>()
    for build_info in build_frame{
        let item = [build_info[0], build_info[1], build_info[2]]
//        answer.append(item)
        // 0 : 삭제, 1 : 설치
        if build_info[3] == 1{
            answer.insert(item)
            if !impossible(answer){
                answer.remove(item)
            }
        }else if build_info[3] == 0{
            if(answer.contains(item)){
                answer.remove(item)
                if !impossible(answer){
                    answer.insert(item)
                }
            }
        }
    }
    result = answer.map { Array<Int>($0) }
    result.sort(by: sortAcc)
    
    return result
}

