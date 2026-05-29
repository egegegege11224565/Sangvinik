import vk_api
from vk_api.longpoll import VkLongPoll, VkEventType
from vk_api.exceptions import ApiError
from dotenv import load_dotenv
import os, random, time

load_dotenv()
vk_session = vk_api.VkApi(token=os.getenv("VK_TOKEN"))
vk = vk_session.get_api()
longpoll = VkLongPoll(vk_session)

def send_message(user_id, text):
    vk.messages.send(
        user_id=user_id,
        message=text,
        random_id=random.randint(0, 10000)
    )

def handle(event):
    text = event.text.lower()
    if text == "привет":
        send_message(event.user_id, "Привет!")
    elif text == "пока":
        send_message(event.user_id, "До свидания!")
    else:
        send_message(event.user_id, f"Ты написал: {text}")

print("Бот запущен...")

while True:
    try:
        for event in longpoll.listen():
            if event.type == VkEventType.MESSAGE_NEW and event.to_me:
                handle(event)
    except ApiError as e:
        print(f"Ошибка API: {e}")
        time.sleep(5)
    except Exception as e:
        print(f"Ошибка: {e}")
        time.sleep(5)
        # Почитать документтацию к библиотекам чтобы детально разобраться прочекать пример на репозитории"https://github.com/python273/vk_api"