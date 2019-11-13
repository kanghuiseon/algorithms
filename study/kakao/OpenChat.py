def solution(record):
    answer = []
    User_dict = {}

    for info in record:
        user_info = info.split(" ")
        if user_info[0] == "Enter":
            User_dict[user_info[1]] = user_info[2]
        elif user_info[0] == "Change":
            User_dict[user_info[1]] = user_info[2]
    for info in record:
        user_info = info.split(" ")
        Chat = User_dict[user_info[2]]
        if user_info[0] == "Enter":
            Chat += "님이 들어왔습니다."
        elif user_info[0] == "Leave":
            Chat += "님이 나갔습니다."
        answer.append(Chat)
    return answer
