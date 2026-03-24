import json

def remove_duplicates(transactions):
    seen = set()
    result = []

    for t in transactions:
        tid = t["transaction_id"]
        if tid not in seen:
            seen.add(tid)
            result.append(t)

    return result


# Leer archivo JSON
with open("transaction_data.json", "r") as file:
    transactions = json.load(file)

clean_transactions = remove_duplicates(transactions)

# 🔥 IMPRIMIR TODOS LOS RESULTADOS
for t in clean_transactions:
    print(t)

print("Total sin duplicados:", len(clean_transactions))