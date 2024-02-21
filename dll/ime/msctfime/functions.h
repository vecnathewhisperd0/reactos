/*
 * PROJECT:     ReactOS msctfime.ime
 * LICENSE:     LGPL-2.1-or-later (https://spdx.org/licenses/LGPL-2.1-or-later)
 * PURPOSE:     The functions of msctfime.ime
 * COPYRIGHT:   Copyright 2024 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>
 */

class CFunctionProviderBase : public ITfFunctionProvider
{
protected:
    TfClientId m_clientId;
    GUID m_guid;
    BSTR m_bstr;
    LONG m_cRefs;

public:
    CFunctionProviderBase(_In_ TfClientId clientId);
    virtual ~CFunctionProviderBase();

    // IUnknown interface
    STDMETHODIMP QueryInterface(_In_ REFIID riid, _Out_ LPVOID* ppvObj) override;
    STDMETHODIMP_(ULONG) AddRef() override;
    STDMETHODIMP_(ULONG) Release() override;

    // ITfFunctionProvider interface
    STDMETHODIMP GetType(_Out_ GUID *guid) override;
    STDMETHODIMP GetDescription(_Out_ BSTR *desc) override;
    //STDMETHODIMP GetFunction(_In_ REFGUID guid, _In_ REFIID riid, _Out_ IUnknown **func) = 0;

    BOOL Init(_In_ REFGUID rguid, _In_ LPCWSTR psz);
};

/***********************************************************************/

class CFunctionProvider : public CFunctionProviderBase
{
public:
    CFunctionProvider(_In_ TfClientId clientId);

    STDMETHODIMP GetFunction(_In_ REFGUID guid, _In_ REFIID riid, _Out_ IUnknown **func) override;
};

/***********************************************************************/

class CFnDocFeed : public IAImmFnDocFeed
{
    LONG m_cRefs;

public:
    CFnDocFeed();
    virtual ~CFnDocFeed();

    // IUnknown interface
    STDMETHODIMP QueryInterface(_In_ REFIID riid, _Out_ LPVOID* ppvObj) override;
    STDMETHODIMP_(ULONG) AddRef() override;
    STDMETHODIMP_(ULONG) Release() override;

    // IAImmFnDocFeed interface
    STDMETHODIMP DocFeed() override;
    STDMETHODIMP ClearDocFeedBuffer() override;
    STDMETHODIMP StartReconvert() override;
    STDMETHODIMP StartUndoCompositionString() override;
};