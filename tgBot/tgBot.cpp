#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>    //базовые средства виндоус
#include <winhttp.h>    //запросы в интернет
#include <string>       
#include <cstdlib>      //чтение переменной окружения
#include <cstring>      //подсчет длины строки
#pragma comment(lib, "winhttp.lib") // подключение библиотеки winhttplib


std::string httpGet(const std::wstring& path)
{
    std::string result; //ответ сервера

    // Открыть сессию 

    HINTERNET hSession = WinHttpOpen(
        L"TgBot/XyePutola/V001",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, // системные настройки
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS,
        0);
    if (!hSession) return result; //возращаем пустую строку если не сработало

    // Соединить с сервером ТГ

    HINTERNET hConnect = WinHttpConnect(
        hSession,
        L"api.telegram.org", // адрес сервера
        INTERNET_DEFAULT_HTTPS_PORT,
        0);

    // Сам запрос || метод GET и путь

    HINTERNET hRequest = nullptr;
    if (hConnect)
    {
        hRequest = WinHttpOpenRequest(
            hConnect,
            L"GET",         // тип запроса
            path.c_str(),    // путь после адреса сайта
            nullptr,
            WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_SECURE); // включить шифрование
    }

    // Отправляем запрос + чтение ответа если удалось отправить

    if (hRequest &&
        WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0) &&
        WinHttpReceiveResponse(hRequest, nullptr)
        )
    {
        DWORD size = 0; // свободное кол-во байтов 
        do {
            size = 0;
            if (!WinHttpQueryDataAvailable(hRequest, &size) || size == 0)
                break;
            std::string buffer(size, '\0');
            DWORD read = 0;
            if (!WinHttpReadData(hRequest, &buffer[0], size, &read))
                break;
            result.append(buffer, 0, read);
        } while (size > 0);
    }
    if (hRequest) WinHttpCloseHandle(hRequest);

    // Читаем ответ

        DWORD size = 0; // сколько байт доступно прямо сейчас
    do
    {
        size = 0;
        if (!WinHttpQueryDataAvailable(hRequest, &size) || size == 0) // спрашиваем, сколько данных можно прочитать
            break;
        std::string buffer(size, '\0');                               //готовим буффер
        DWORD read = 0;                                               // сколько байт прочитали
        if (!WinHttpReadData(hRequest, &buffer[0], size, &read))
            break;
        result.append(buffer, 0, read);                               // добавляем прочитанное в общий результат
    } while (size > 0);

    // закрываем 
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);

    return result;

}
int main()
{ 
            SetConsoleOutputCP(CP_UTF8);

            const char* token = std::getenv("BOT_TOKEN"); // читаем переменную заданную в настройке проекта
            if (!token)
            {
                std::cout << "BOT_TOKEN не задана\n";
                return 1;       //ошибка
            }
        
    std::wstring path = L"/bot" + std::wstring(token, token + std::strlen(token)) + L"/getUpdates"; //печатаем ответ
    std::cout << httpGet(path) << "\n";
    return 0;
}