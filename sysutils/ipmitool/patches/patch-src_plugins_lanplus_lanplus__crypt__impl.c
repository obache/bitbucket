$NetBSD: patch-src_plugins_lanplus_lanplus__crypt__impl.c,v 1.1 2017/12/22 21:45:23 markd Exp $

--- src/plugins/lanplus/lanplus_crypt_impl.c	2016-05-28 10:20:20.000000000 +0200
+++ src/plugins/lanplus/lanplus_crypt_impl.c	2017-02-21 10:50:21.634873466 +0100
@@ -164,10 +164,10 @@ lanplus_encrypt_aes_cbc_128(const uint8_
 							uint8_t       * output,
 							uint32_t        * bytes_written)
 {
-	EVP_CIPHER_CTX ctx;
-	EVP_CIPHER_CTX_init(&ctx);
-	EVP_EncryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL, key, iv);
-	EVP_CIPHER_CTX_set_padding(&ctx, 0);
+	EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
+	EVP_CIPHER_CTX_init(ctx);
+	EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);
+	EVP_CIPHER_CTX_set_padding(ctx, 0);
 	
 
 	*bytes_written = 0;
@@ -191,7 +191,7 @@ lanplus_encrypt_aes_cbc_128(const uint8_
 	assert((input_length % IPMI_CRYPT_AES_CBC_128_BLOCK_SIZE) == 0);
 
 
-	if(!EVP_EncryptUpdate(&ctx, output, (int *)bytes_written, input, input_length))
+	if(!EVP_EncryptUpdate(ctx, output, (int *)bytes_written, input, input_length))
 	{
 		/* Error */
 		*bytes_written = 0;
@@ -201,7 +201,7 @@ lanplus_encrypt_aes_cbc_128(const uint8_
 	{
 		uint32_t tmplen;
 
-		if(!EVP_EncryptFinal_ex(&ctx, output + *bytes_written, (int *)&tmplen))
+		if(!EVP_EncryptFinal_ex(ctx, output + *bytes_written, (int *)&tmplen))
 		{
 			*bytes_written = 0;
 			return; /* Error */
@@ -210,7 +210,8 @@ lanplus_encrypt_aes_cbc_128(const uint8_
 		{
 			/* Success */
 			*bytes_written += tmplen;
-			EVP_CIPHER_CTX_cleanup(&ctx);
+			EVP_CIPHER_CTX_cleanup(ctx);
+			EVP_CIPHER_CTX_free(ctx);
 		}
 	}
 }
@@ -239,10 +240,10 @@ lanplus_decrypt_aes_cbc_128(const uint8_
 							uint8_t       * output,
 							uint32_t        * bytes_written)
 {
-	EVP_CIPHER_CTX ctx;
-	EVP_CIPHER_CTX_init(&ctx);
-	EVP_DecryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL, key, iv);
-	EVP_CIPHER_CTX_set_padding(&ctx, 0);
+	EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
+	EVP_CIPHER_CTX_init(ctx);
+	EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);
+	EVP_CIPHER_CTX_set_padding(ctx, 0);
 
 
 	if (verbose >= 5)
@@ -266,7 +267,7 @@ lanplus_decrypt_aes_cbc_128(const uint8_
 	assert((input_length % IPMI_CRYPT_AES_CBC_128_BLOCK_SIZE) == 0);
 
 
-	if (!EVP_DecryptUpdate(&ctx, output, (int *)bytes_written, input, input_length))
+	if (!EVP_DecryptUpdate(ctx, output, (int *)bytes_written, input, input_length))
 	{
 		/* Error */
 		lprintf(LOG_DEBUG, "ERROR: decrypt update failed");
@@ -277,7 +278,7 @@ lanplus_decrypt_aes_cbc_128(const uint8_
 	{
 		uint32_t tmplen;
 
-		if (!EVP_DecryptFinal_ex(&ctx, output + *bytes_written, (int *)&tmplen))
+		if (!EVP_DecryptFinal_ex(ctx, output + *bytes_written, (int *)&tmplen))
 		{
 			char buffer[1000];
 			ERR_error_string(ERR_get_error(), buffer);
@@ -290,7 +291,8 @@ lanplus_decrypt_aes_cbc_128(const uint8_
 		{
 			/* Success */
 			*bytes_written += tmplen;
-			EVP_CIPHER_CTX_cleanup(&ctx);
+			EVP_CIPHER_CTX_cleanup(ctx);
+			EVP_CIPHER_CTX_free(ctx);
 		}
 	}
 
