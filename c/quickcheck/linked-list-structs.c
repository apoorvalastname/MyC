#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30
typedef struct _Data
{
    char *name;
    char *others;
}Data;

typedef struct _TxData
{
    char *txid;
    Data *data;
    struct _TxData *next;
}TxData;

TxData *txHead = NULL;

static TxData *txDataFind (char *txid)
{
    TxData *tx = txHead;
    for (; tx!=NULL; tx=tx->next)
        if (!strcasecmp(txid,tx->txid))
            break;
    return tx;
}

void txDataDelete (char *txid)
{
    if (!txid || !txHead)
        return;
    // Delete the head
    TxData *tx = txHead;
    if (!strcasecmp(txid,tx->txid))
    {
       txHead = txHead->next;
       free (tx);
       return; 
    }
    tx = tx->next;
    TxData *prev = txHead;
    for (; tx; prev=prev->next, tx=tx->next)
    {
        if (!strcasecmp(txid,tx->txid))
        {
            prev->next = tx->next;
            free (tx);
            return;
        }
    }
}

void txDataPrintEntry (TxData *tx)
{
    if (!tx || !tx->txid)
        return;
   
    printf ("\n Tx - txid : %s", tx->txid);
    if (!tx->data)
        return;
    
    if (tx->data->name)
        printf ("\n Tx - name : %s", tx->data->name);
    if (tx->data->others)
        printf ("\n Tx - other info : %s", tx->data->others);
}
void txDataPrint (char *txid)
{
    if (!txid || !txHead)
        return;

    txDataPrintEntry(txDataFind (txid));
}

void txDataUpdateEntry (TxData *tx)
{
    char name[MAX_LEN], others[MAX_LEN];
    printf ("\n Enter the name of this transaction %s : ",tx->txid);
    scanf ("%s", name);
    printf ("\n Enter the other information of this transaction %s : ",tx->txid);
    scanf ("%s", others);
    if (!tx->data)
        tx->data = calloc (1, sizeof (Data)); 
    if (tx->data->name)
        free (tx->data->name);
    if (tx->data->others)
        free (tx->data->others);
    tx->data->name   = strdup (name);
    tx->data->others = strdup (others);
}

void txDataCreate (char *txid)
{
    TxData *tx = txDataFind(txid);
    // Entry already exists, no need to create again - print or delete
    if (tx)
    {
        char pd;
        printf ("\n Txid : %s exists!\n Do you want to print / delete / update the transaction details: (p/d/u) -", txid);
        scanf (" %c", &pd);
        if (pd == 'd' || pd == 'D')
            txDataDelete (txid);
        else if (pd == 'u' || pd == 'U')
            txDataUpdateEntry (tx);
        else
            txDataPrintEntry(tx);
        return;
    }
    // Entry doesn't exist, create
    tx = calloc(1, sizeof (TxData));
    tx->txid = strdup (txid);
    txDataUpdateEntry (tx); 
    // If no head, create head
    if (!txHead)
    {
        txHead = tx;    
    }
    else
    {
        TxData *tmpTx = txHead;
        for (; tmpTx->next; tmpTx = tmpTx->next);
        tmpTx->next = tx;
    }

    return;
}

int main()
{
    // Get Transaction id from the user
    // Check if the transaction id already exists
    // If exists, ask if it needs to printed or deleted
    // If does not exist, create one - accept input config from the user.
    // print transaction config
    // delete transaction

    // list of available transactions
    char txid[MAX_LEN];
    char dum,yn;
    do 
    {
        memset (txid, 0, MAX_LEN);
        printf ("\n Enter the txid, and let me find the details for you : ");
        scanf("%s", txid);
        txDataCreate (txid);
        printf ("\n Do you wish to continue ?(y/n) :");
        scanf(" %c",&yn);
    } while (yn=='y' || yn=='Y');
}
