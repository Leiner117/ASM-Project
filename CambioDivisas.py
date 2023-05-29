import requests
from dateutil.parser import parse 

def get_all_exchange_rates_erapi(src):
    url = f"https://open.er-api.com/v6/latest/{src}"
    # request the open ExchangeRate API and convert to Python dict using .json()
    data = requests.get(url).json()
    if data["result"] == "success":
        # request successful
        # get the last updated datetime
        last_updated_datetime = parse(data["time_last_update_utc"])
        # get the exchange rates
        exchange_rates = data["rates"]
    return last_updated_datetime, exchange_rates

def convert_currency_erapi(src, dst, amount):
    # get all the exchange rates
    last_updated_datetime, exchange_rates = get_all_exchange_rates_erapi(src)
    # convert by simply getting the target currency exchange rate and multiply by the amount
    return last_updated_datetime, exchange_rates[dst] * amount

cambios = {}
if __name__ == "__main__":
    divisas = ["USD","CRC","EUR"]
    i = 0
    file = open(r"C:\Users\leine\OneDrive\Documentos\GitHub\ASM-Project\cambioDivisa.txt","w")
    while i < len(divisas):
        a = 0
        while a < len(divisas):
            if divisas[a] == divisas[i]:
                a = a+1
                continue
            source_currency = divisas[i]
            destination_currency = divisas[a]
            amount = float(1)
            
            last_updated_datetime, exchange_rate = convert_currency_erapi(source_currency, destination_currency, amount)
            cambioDivisa = str(last_updated_datetime.date())+"|"+str(source_currency)+"|"+str(destination_currency)+"|"+str(exchange_rate)+"\n"
            
            file.write(cambioDivisa)
            a = a +1
        i = i+1
    file.close()

