import Foundation

func solution(_ cacheSize:Int, _ cities:[String]) -> Int {
    var cache:[String] = []
    var answer = 0;
    if(cacheSize == 0){
        return cities.count * 5
    }
    var tmp = cities
    for i in 0..<tmp.count{
        tmp[i] = tmp[i].lowercased()
    }
    for i in 0..<tmp.count{
        if(!cache.contains(tmp[i])){
            if(cache.count == cacheSize){
                cache.remove(at: 0)
                cache.append(tmp[i])
                answer += 5
                continue
            }
            cache.append(tmp[i])
            answer += 5
        }
        else{
            var index = 0
            for (idx, value) in cache.enumerated() {
                if(value == tmp[i]){
                    index = idx
                }
            }
            let temp = cache.remove(at: index)
            cache.insert(temp, at: cache.endIndex)
            answer += 1
        }
    }
    return answer
}
